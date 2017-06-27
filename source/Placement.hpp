#ifndef PLACEMENT_HPP
#define PLACEMENT_HPP

#include "Vector2.hpp"

class Placement {
public:
	using Weight = Vector2::Type;

public:
	Placement(std::vector<Weight> const& positions_horizontal, std::vector<Weight> const& positions_vertical);

	std::size_t num_rectangles() const;

	Vector2 area() const;
	Vector2 position(std::size_t const& rectangle_index) const;


private:
	std::vector<Weight> _positions_horizontal;
	std::vector<Weight> _positions_vertical;
};


#endif
