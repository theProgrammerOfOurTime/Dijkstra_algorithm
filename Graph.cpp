#include "Graph.h"
#include <iostream>

void Graph::input()
{
	std::cin >> vertexes_number;
	std::cin >> edges_number;
	list.clear();
	for (vertex_t i = 0; i < edges_number; i++)
	{
		vertex_t a, b;
		weight w;
		std::cin >> a >> b >> w;
		infinity += w;
		list[a].insert(std::make_pair(b, w));
		list[b].insert(std::make_pair(a, w));
	}
}

void  Graph::print() const
{
	std::cout << "Vertexes number = " << vertexes_number << std::endl;
	for (auto vertex : list)
	{
		std::cout << vertex.first << ": { ";
		for (auto adjacent_vertex : vertex.second)
		{
			std::cout << adjacent_vertex.first << " ";
		}
		std::cout << "}" << std::endl;
	}
}

Graph::vertex_t Graph::searchMin(std::vector<weight> vertex_weight, std::vector<bool> used) const
{
	vertex_t indexMin = 0, minWeight = infinity;
	for (int i = 1; i < vertexes_number; i++)
	{
		if (used[i] == false && vertex_weight[i] < minWeight)
		{
			indexMin = i;
			minWeight = vertex_weight[i];
		}
	}
	return indexMin;
}

Graph::weight Graph::Dijkstra_àlgorithm(vertex_t a, vertex_t b)
{
	std::vector<bool> used(vertexes_number);
	std::vector<weight> vertex_weight(vertexes_number, infinity);
	vertex_weight[a] = 0;
	vertex_t index_min_vertex = a;
	while(index_min_vertex != b)
	{
		used[index_min_vertex] = true;
		for (auto adjacent_vertex : list[index_min_vertex])
		{
			if (used[adjacent_vertex.number_vertex] == true) { continue; }
			weight new_weight = adjacent_vertex.weight_edge + vertex_weight[index_min_vertex];
			if (new_weight < vertex_weight[adjacent_vertex.number_vertex])
			{
				vertex_weight[adjacent_vertex.number_vertex] = new_weight;
			}
		}
		index_min_vertex = searchMin(vertex_weight, used);
	}
	return vertex_weight[b];
}