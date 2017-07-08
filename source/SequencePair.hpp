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

	/**
	 * Update the given graphs with respect to the current sequence pair
	 * this needs time in O(n^2)
	 * @param graph_minus
	 * @param graph_plus
	 */
	void update_graphs(Graph& graph_minus, Graph& graph_plus);

private:
	// maps from the permutation position to the module/rectangle
	// keep in mind: this is the other way around as in the script
	std::vector<std::size_t> _gamma_minus;
	std::vector<std::size_t> _gamma_plus;

	IterativeBooleanAssignment _before;
};


#endif
