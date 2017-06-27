#ifndef SEQUENCEPAIR_HPP
#define SEQUENCEPAIR_HPP

#include <vector>

#include "Graph.hpp"

class SequencePair {
public:
	SequencePair(std::size_t const& length);

	std::size_t length() const;

	std::vector<std::size_t> const& gamma_minus() const;
	std::vector<std::size_t> const& gamma_plus() const;

	bool next_gamma_minus();
	bool next_gamma_plus();

	void update_graphs(Graph& graph_minus, Graph& graph_plus);

private:
	std::vector<std::size_t> _gamma_minus;
	std::vector<std::size_t> _gamma_plus;

	IterativeBooleanAssignment _before;
};


#endif
