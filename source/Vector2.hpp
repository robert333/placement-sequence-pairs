#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <vector>

class Vector2 {
public:
	using Vector = std::vector<Vector2>;

public:
	static Vector2 invalid();

public:
	using Type = unsigned long long int;

	explicit Vector2(Type const& x, Type const& y);

	Type const& x() const;
	Type const& y() const;

private:
	Type _x;
	Type _y;
};


#endif
