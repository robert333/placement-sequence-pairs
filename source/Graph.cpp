#include "Graph.hpp"

Graph::Graph(std::size_t const& num_vertices, std::vector<Weight> const& weights) :
	_num_vertices(num_vertices),
	_weights(weights),
	_topological_order(num_vertices),
	_visited(num_vertices)
{}

void Graph::reset()
{
	_neighbours.assign(_num_vertices, {});
}

void Graph::add_neighbour(std::size_t const& vertex, std::size_t const& neighbour)
{
	_neighbours.at(vertex).push_back(neighbour);
}

bool Graph::compute_longest_paths(std::vector<Weight>& lengths, Weight const& upper_bound)
{
	lengths.assign(_num_vertices + 1, 0);

	compute_topological_order();

	for (std::size_t const& vertex : _topological_order.order()) {
		Weight const& weight = _weights.at(vertex);
		Vertices const& neighbours = _neighbours.at(vertex);

		if (neighbours.empty()) {
			if (lengths.at(_num_vertices) < lengths.at(vertex) + weight) {
				lengths.at(_num_vertices) = lengths.at(vertex) + weight;

				if (lengths.at(_num_vertices) >= upper_bound) {
					return false;
				}
			}
		} else {
			for (std::size_t const& neighbour : _neighbours.at(vertex)) {
				if (lengths.at(neighbour) < lengths.at(vertex) + weight) {
					lengths.at(neighbour) = lengths.at(vertex) + weight;

					if (lengths.at(neighbour) >= upper_bound) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

void Graph::compute_topological_order()
{
	_topological_order.reset();

	for (std::size_t vertex = 0; vertex < _num_vertices; ++vertex) {
		if (not _visited.get(vertex)) {
			topological_sort(vertex);
		}
	}

	_visited.reset();
}

void Graph::topological_sort(std::size_t const& vertex)
{
	_visited.assign(vertex, true);

	for (std::size_t const& neighbour : _neighbours.at(vertex)) {
		if (not _visited.get(neighbour)) {
			topological_sort(neighbour);
		}
	}

	_topological_order.push(vertex);
}
