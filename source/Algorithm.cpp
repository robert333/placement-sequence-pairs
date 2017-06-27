#include "Algorithm.hpp"

#include <limits>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <chrono>

#include "SequencePair.hpp"

Placement Algorithm::compute_minimum_placement(Instance const& instance)
{
	std::size_t const num_rectangles = instance.num_rectangles();

	SequencePair sequence_pair(instance.num_rectangles());

	Graph graph_horizontal(instance.num_rectangles(), instance.widths());
	Graph graph_vertical(instance.num_rectangles(), instance.heights());

	std::vector<Weight> lengths_horizontal(num_rectangles + 1);
	std::vector<Weight> lengths_vertical(num_rectangles + 1);

//	Weight min_width = std::min_element(instance.widths().begin(), instance.widths().end()).operator*();
//	Weight min_height = std::min_element(instance.heights().begin(), instance.heights().end()).operator*();

//	Weight max_width = std::max_element(instance.widths().begin(), instance.widths().end()).operator*();
	Weight max_height = std::max_element(instance.heights().begin(), instance.heights().end()).operator*();

	Weight max_area_horizontal = static_cast<Weight>(std::accumulate(instance.widths().begin(), instance.widths().end(), 0));
//	Weight max_area_vertical = static_cast<Weight>(std::accumulate(instance.heights().begin(), instance.heights().end(), 0));

	std::vector<Weight> min_lengths_horizontal(num_rectangles + 1, std::numeric_limits<Weight>::max());
	std::vector<Weight> min_lengths_vertical(num_rectangles + 1, std::numeric_limits<Weight>::max());

	Weight current_min_area = max_area_horizontal * max_height;

	// output number of cases which must be checked
	Weight cases = 1;
	for (std::size_t i = 0; i < num_rectangles; ++i) {
		cases *= i + 1;
	}
	cases *= cases;

	std::cout << "There will be checked " << cases << " cases:\n\n";

	// initialize progress variable
	Weight k = 0;
	Weight p = 0;

	std::chrono::high_resolution_clock::time_point const time_start_point = std::chrono::high_resolution_clock::now();

	do {
		do {
			sequence_pair.update_graphs(graph_horizontal, graph_vertical);

			if (graph_horizontal.compute_longest_paths(lengths_horizontal, current_min_area / max_height + 1)) {
				if (graph_vertical.compute_longest_paths(lengths_vertical, current_min_area / lengths_horizontal.at(num_rectangles) + 1)) {
					if (current_min_area > lengths_horizontal.at(num_rectangles) * lengths_vertical.at(num_rectangles)) {
						min_lengths_horizontal = lengths_horizontal;
						min_lengths_vertical = lengths_vertical;
						current_min_area = min_lengths_horizontal.at(num_rectangles) * min_lengths_vertical.at(num_rectangles);
					}
				}
			}

			// output progress
			if (++k >= cases / 10 * (p + 1)) {
				std::chrono::high_resolution_clock::time_point const time_stop_point = std::chrono::high_resolution_clock::now();
				std::cout << "progress: " << ++p << "0% (" << std::chrono::duration_cast<std::chrono::seconds>(time_stop_point - time_start_point).count() << " sec) current area size: " << current_min_area << "\n";
			}
		} while (sequence_pair.next_gamma_plus());
	} while (sequence_pair.next_gamma_minus());

	return Placement(min_lengths_horizontal, min_lengths_vertical);
}

void Algorithm::output(std::ostream& ostream, Instance const& instance)
{
	for (std::size_t rectangle_index = 0; rectangle_index < instance.num_rectangles(); ++rectangle_index) {
		ostream << instance.size(rectangle_index).x() << " " << instance.size(rectangle_index).y() << "\n";
	}
}

void Algorithm::output(std::ostream& ostream, Placement const& placement)
{
	ostream << placement.area().x() << " " << placement.area().y() << "\n";

	for (std::size_t rectangle_index = 0; rectangle_index < placement.num_rectangles(); ++rectangle_index) {
		ostream << placement.position(rectangle_index).x() << " " << placement.position(rectangle_index).y() << "\n";
	}
}

void Algorithm::gnuplot(std::ostream& ostream, Instance const& instance, Placement const& placement, std::string const& title)
{
	ostream << "set size ratio -1\n"
			<< "set style rectangle fs solid\n";

	std::vector<std::string> colours = {"blue", "red", "green", "orange", "cyan", "violet", "gold"};

	for (std::size_t rectangle_index = 0; rectangle_index < placement.num_rectangles(); ++rectangle_index) {
		ostream << "set object rectangle from "
				<< placement.position(rectangle_index).x() << "," << placement.position(rectangle_index).y()
				<< " to " << placement.position(rectangle_index).x() + instance.size(rectangle_index).x()
				<< "," << placement.position(rectangle_index).y() + instance.size(rectangle_index).y()
				<< " fc rgb \"" << colours.at(rectangle_index % colours.size()) << "\"\n";
		ostream << "set label \"" << rectangle_index << "\" at "
				<< placement.position(rectangle_index).x() + 0.5 * instance.size(rectangle_index).x() - 0.25
				<< "," << placement.position(rectangle_index).y() + 0.5 * instance.size(rectangle_index).y()
				<< " textcolor rgb \"black\"\n";
	}

	ostream << "set title \"" << title << "\"\n";

	ostream << "plot [" << 0 << ":" << placement.area().x() << "] [" << 0 << ":" << placement.area().y() << "] NaN notitle\n";
}
