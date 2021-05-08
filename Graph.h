#pragma once
#include <map>
#include <set>
#include <vector>

class Graph
{
private:
	typedef int32_t vertex_t, weight;
	#define weight_edge second
	#define number_vertex first
	int vertexes_number, edges_number;
	std::map <vertex_t, std::set<std::pair<vertex_t, weight>>> list; //list of adjecency
	weight infinity;
	vertex_t searchMin(std::vector<weight>, std::vector<bool>) const;
public:
	Graph() : vertexes_number(0), edges_number(0), infinity(1) {}
	void input();
	void print() const;
	weight Dijkstra_àlgorithm(vertex_t, vertex_t);
};