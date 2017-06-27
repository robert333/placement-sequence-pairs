#ifndef ITERATIVEBOOLEANASSIGNMENT_HPP
#define ITERATIVEBOOLEANASSIGNMENT_HPP

#include <vector>

class IterativeBooleanAssignment {
public:
	using Container = std::vector<char>;

public:
	IterativeBooleanAssignment(std::size_t const& length);

	void assign(std::size_t const& index, bool const& value);
	bool get(std::size_t const& index) const;
	void reset();

private:
	bool _current_true_value;
	Container _assignment;
};

#endif
