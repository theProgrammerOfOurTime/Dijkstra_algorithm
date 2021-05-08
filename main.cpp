#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph graph;
	graph.input();
	graph.print();
	int a, b;
	cin >> a >> b;
	cout << graph.Dijkstra_аlgorithm(a, b) << endl;
    return 0;
}