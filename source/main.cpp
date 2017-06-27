#include <iostream>
#include <fstream>

#include <cassert>

#include "Instance.hpp"
#include "Placement.hpp"
#include "Algorithm.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "argument needed: " << argv[0] << " *instance_filepath*\n";
		return 1;
	}

	std::string const instance_filepath = argv[1];

	std::ifstream instance_file(instance_filepath);

	if (not instance_file.is_open()) {
		std::cerr << "ERROR: cannot open instance file " << instance_filepath << "\n";
		return 1;
	}

	Instance instance;

	try{
		instance.parse(instance_file);
	} catch(...) {
		std::cerr << "ERROR: cannot parse instance file " << instance_filepath << "\n";
		return 1;
	}

	Algorithm::output(std::cout, instance);

	Placement const placement = Algorithm::compute_minimum_placement(instance);

	Algorithm::output(std::cout, placement);

	if (argc > 2 and std::string(argv[2]) == "gnuplot") {
		std::ofstream gnuplot_file(instance_filepath + "_gnuplot");

		assert(gnuplot_file.is_open());
		Algorithm::gnuplot(gnuplot_file, instance, placement, instance_filepath);
		gnuplot_file.close();

		std::string const command = "gnuplot -persistent " + instance_filepath + "_gnuplot";

		std::cout << "for gnuplot use the following command:\n"
				  << command << "\n";


		//DEBUG
		int status = system(command.c_str());
		assert(not status);

		std::cout << "Enter to exit the program...";
		std::cin.ignore().get();
	}

	return 0;
}