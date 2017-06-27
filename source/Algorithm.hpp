#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "Instance.hpp"
#include "Placement.hpp"

class Algorithm {
public:
	using Weight = Vector2::Type;

public:
	static Placement compute_minimum_placement(Instance const& instance);

	static void output(std::ostream& ostream, Instance const& instance);
	static void output(std::ostream& ostream, Placement const& placement);
	static void gnuplot(std::ostream& ostream, Instance const& instance, Placement const& placement, std::string const& title);

private:
	Algorithm() = default;
};


#endif
