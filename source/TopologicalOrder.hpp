#ifndef TOPOLOGICALORDER_HPP
#define TOPOLOGICALORDER_HPP

#include <vector>

class TopolocialOrder {
public:
	TopolocialOrder(std::size_t const& num_vertices);

	void reset();
	void push(std::size_t const& index);

	std::vector<std::size_t> const& order() const;

private:
	std::size_t _valid_position;
	std::vector<std::size_t> _order;
};


#endif
