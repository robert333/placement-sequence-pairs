#include "Vector2.hpp"

#include <limits>

Vector2 Vector2::invalid()
{
	return Vector2(std::numeric_limits<Type>::max(), std::numeric_limits<Type>::max());
}

Vector2::Vector2(Vector2::Type const& x, Vector2::Type const& y) :
	_x(x),
	_y(y)
{}

Vector2::Type const& Vector2::x() const
{
	return _x;
}

Vector2::Type const& Vector2::y() const
{
	return _y;
}
