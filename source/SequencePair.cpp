#include "SequencePair.hpp"

#include <algorithm>

SequencePair::SequencePair(std::size_t const& length) :
	_gamma_minus(length),
	_gamma_plus(length),
	_before(length)
{
	for (std::size_t i = 0; i < length; ++i) {
		_gamma_minus.at(i) = i;
		_gamma_plus.at(i) = i;
	}
}

std::size_t SequencePair::length() const
{
	return _gamma_minus.size();
}

std::vector<std::size_t> const& SequencePair::gamma_minus() const
{
	return _gamma_minus;
}

std::vector<std::size_t> const& SequencePair::gamma_plus() const
{
	return _gamma_plus;
}

bool SequencePair::next_gamma_minus()
{
	return std::next_permutation(_gamma_minus.begin(), _gamma_minus.end());
}

bool SequencePair::next_gamma_plus()
{
	return std::next_permutation(_gamma_plus.begin(), _gamma_plus.end());
}

void SequencePair::update_graphs(Graph& graph_minus, Graph& graph_plus)
{
	graph_minus.reset();
	graph_plus.reset();

	// minus
	for (std::size_t i = 0; i < length(); ++i) {
		for (std::size_t j = 0; gamma_minus().at(j) != gamma_plus().at(i); ++j) {
			if (_before.get(gamma_minus().at(j))) {
				graph_minus.add_neighbour(gamma_minus().at(j), gamma_plus().at(i));
			}
		}

		_before.assign(gamma_plus().at(i), true);
	}

	_before.reset();

	// plus
	for (std::size_t j = 0; j < length(); ++j) {
		for (std::size_t i = length() - 1; gamma_plus().at(i) != gamma_minus().at(j); --i) {
			if (_before.get(gamma_plus().at(i))) {
				graph_plus.add_neighbour(gamma_plus().at(i), gamma_minus().at(j));
			}
		}

		_before.assign(gamma_minus().at(j), true);
	}

	_before.reset();

//			graphHorizontal.removeAllTransitiveClosureEdges ();
//			graphVertical  .removeAllTransitiveClosureEdges ();
}
