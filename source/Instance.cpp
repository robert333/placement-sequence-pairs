#include "Instance.hpp"

#include <sstream>

std::size_t Instance::num_rectangles() const
{
	return _widths.size();
}

std::vector<Instance::Weight> const& Instance::widths() const
{
	return _widths;
}

std::vector<Instance::Weight> const& Instance::heights() const
{
	return _heights;
}

Vector2 Instance::size(std::size_t const& rectangle_index) const
{
	return Vector2(_widths.at(rectangle_index), _heights.at(rectangle_index));
}

void Instance::parse(std::ifstream& ifstream)
{
	if (num_rectangles() != 0) {
		throw;
	}

	if (not ifstream.is_open()) {
		throw;
	}

	std::string line;
	std::stringstream stringstream;

	std::getline(ifstream, line);
	stringstream.clear();
	stringstream.str(line);

	std::size_t num;

	stringstream >> num;

	Vector2::Type width;
	Vector2::Type height;

	while (std::getline(ifstream, line)) {
		stringstream.clear();
		stringstream.str(line);

		stringstream >> width;
		stringstream >> height;

		_widths.push_back(width);
		_heights.push_back(height);
	}

	if (num_rectangles() != num) {
		throw;
	}
}
