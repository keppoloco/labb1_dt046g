/*#include "Bfs.h"
#include <iostream>
#include <vector>

void bfs(const adjacency_list_t& list)
{
	// Allocate vector size and set default value of all pos to false
	std::vector<bool> visited(list.first.size(), false);

	// Create our queue from struct
	queue q;

	// mark our first node
	push_and_visit(q, list.first.begin()->first, visited);

	while (q.size()) {
		// Get current node
		node_id_t curr_node = q.pop();

		auto neighbour = unvisitedNeighbours(curr_node, list, visited);

		for (auto id : neighbour) {
			push_and_visit(q, id, visited);
		}
	}

	int index = 0;
	for (auto it = visited.begin(); it != visited.end(); it++) {
		std::cout << (*it ? "Connected" : "Disconnected")  << " - Vertex " << list.first.find(index)->first << " : Name: " << list.first.find(index)->second << "\n";
		index++;
	}

	if (isAllVisited(visited)) {
		std::cout << "Graph is valid.\n";
	}
	else {
		std::cout << "Graph is not valid.\n";
	}
}

std::vector<node_id_t> unvisitedNeighbours(node_id_t curr_node, const adjacency_list_t& graph, std::vector<bool>& visited) {
	std::vector<node_id_t> neighbour;
	for (int adjacent_Node = 0; adjacent_Node < graph.second.size(); adjacent_Node++) {
		if (graph.second[adjacent_Node].n1 == curr_node) {
			if (!isVisited(graph.second[adjacent_Node].n2, visited)) {
				neighbour.push_back(graph.first.find(graph.second[adjacent_Node].n2)->first);
			}
		}
	}
	return neighbour;
}

bool isVisited(node_id_t node, const std::vector<bool>& visited) {
	if (visited[node])
		return true;
	
	return false;
}

bool isAllVisited(const std::vector<bool>& visited)
{
	return (std::adjacent_find(visited.begin(), visited.end(), std::not_equal_to<>()) == visited.end());
}

void push_and_visit(queue& q, node_id_t node, std::vector<bool>& visited) {
	q.push(node);
	visited[node] = true;
}
*/