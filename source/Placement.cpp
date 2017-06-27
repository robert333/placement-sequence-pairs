#include "Placement.hpp"

Placement::Placement(std::vector<Weight> const& positions_horizontal, std::vector<Weight> const& positions_vertical) :
	_positions_horizontal(positions_horizontal),
	_positions_vertical(positions_vertical)
{}

std::size_t Placement::num_rectangles() const
{
	return _positions_horizontal.size() - 1;
}

Vector2 Placement::area() const
{
	return Vector2(_positions_horizontal.back(), _positions_vertical.back());
}

Vector2 Placement::position(std::size_t const& rectangle_index) const
{
	return Vector2(_positions_horizontal.at(rectangle_index), _positions_vertical.at(rectangle_index));
}
