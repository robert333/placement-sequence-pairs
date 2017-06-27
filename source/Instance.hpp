#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <fstream>

#include "Vector2.hpp"

class Instance {
public:
	using Weight = Vector2::Type;

public:
	Instance() = default;

	std::size_t num_rectangles() const;
	std::vector<Weight> const& widths() const;
	std::vector<Weight> const& heights() const;

	Vector2 size(std::size_t const& rectangle_index) const;

	void parse(std::ifstream& ifstream);

private:
	std::vector<Weight> _widths;
	std::vector<Weight> _heights;
};


#endif
