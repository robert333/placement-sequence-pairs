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
