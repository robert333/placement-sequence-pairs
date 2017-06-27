#include "IterativeBooleanAssignment.hpp"

IterativeBooleanAssignment::IterativeBooleanAssignment(std::size_t const& length) :
	_current_true_value(true),
	_assignment(length, false)
{}

void IterativeBooleanAssignment::assign(std::size_t const& index, bool const& value)
{
	_assignment.at(index) = value ? _current_true_value : not _current_true_value;
}

bool IterativeBooleanAssignment::get(std::size_t const& index) const
{
	return _assignment.at(index) == _current_true_value;
}

void IterativeBooleanAssignment::reset()
{
	_current_true_value = not _current_true_value;
}
