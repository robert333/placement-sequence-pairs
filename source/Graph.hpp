#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <array>

#include "Instance.hpp"
#include "Placement.hpp"
#include "TopologicalOrder.hpp"
#include "IterativeBooleanAssignment.hpp"

class Graph {
public:
	using Weight = Vector2::Type;
	using Vertices = std::vector<size_t>;

public:
	Graph(std::size_t const& num_vertices, std::vector<Weight> const& _weights);

	void reset();

	void add_neighbour(std::size_t const& vertex, std::size_t const& neighbour);

	/**
	 * Computes the longest path in the current graph assuming that it is acyclic
	 *
	 * first a topological order is computed in time in O(n^2)
	 * then the lengths are computed in O(n^2)
	 * in both steps we need O(n^2) time as the number of edges might be in O(n^2)
	 *
	 * @param lengths vector for saving the computed potential of each vertex
	 * @param upper_bound an upper bound to stop as soon as the algorithm finds a longer path
	 * @return true iff the upper bound is not reached
	 */
	bool compute_longest_paths(std::vector<Weight>& lengths, Weight const& upper_bound);

private:
	void compute_topological_order();
	void topological_sort(std::size_t const& vertex);

private:
	std::size_t const _num_vertices;
	std::vector<Weight> const _weights;

	std::vector<Vertices> _neighbours;
	TopolocialOrder _topological_order;

	IterativeBooleanAssignment _visited;
};


#endif
