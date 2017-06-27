#include "TopologicalOrder.hpp"

TopolocialOrder::TopolocialOrder(std::size_t const& num_vertices) :
	_valid_position(num_vertices),
	_order(num_vertices)
{

}

void TopolocialOrder::reset()
{
	_valid_position = _order.size();
}

void TopolocialOrder::push(std::size_t const& index)
{
	_order.at(--_valid_position) = index;
}

std::vector<std::size_t> const& TopolocialOrder::order() const
{
	return _order;
}
