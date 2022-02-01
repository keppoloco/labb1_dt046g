#include "Dijkstras.h"
#include <iostream>
#include <algorithm>
#include <string>

std::vector<std::string> path;

std::string Dijkstras::getNodeName(const adjacency_list_t& graph, const node_id_t node) {
	for (auto it = graph.first.begin(); it != graph.first.end(); it++) {
		if (it->first == node) {
			return it->second;
		}
	}
}

edge Dijkstras::getSource(const adjacency_list_t& graph, const node_id_t node) {
	for (auto it = graph.first.begin(); it != graph.first.end(); it++) {
		if (it->first == node) {
			return edge{ 0, node, 0, it->second };
		}
	}
}

std::vector<edge> Dijkstras::adjacentNodes(const adjacency_list_t& graph, const edge& e) {
	std::vector<edge> neighbours;

	for (int node_id = 0; node_id < graph.second.size(); node_id++) {
		if (graph.second[node_id].n1 == e.n2) {
			neighbours.push_back(graph.second[node_id]);
		}
	}
	return neighbours;
}

Dijkstras::Dijkstras(const adjacency_list_t& graph) {
	std::vector<weight_t> distance(graph.first.size(), std::numeric_limits<double>::max());
	path.resize(graph.first.size());

	node_id_t start_node = 0, destination_node = 0;
	initNodes(start_node, destination_node);

	edge source = getSource(graph, start_node);


	pq.push(source);
	distance[source.n2] = 0;

	while (!pq.empty()) {
		// Get current edge in queue
		edge current = pq.top();
		// Remove the current edge in queue
		pq.pop();

		auto edge_vector = adjacentNodes(graph, current);

		for (auto edge : edge_vector) {
			edge.weight += current.weight;
			if ( edge.weight < distance[edge.n2]) {
				distance[edge.n2] = edge.weight;

				std::string paths;
				paths += " to: " + getNodeName(graph, edge.n2) + '\n';
 
				edge.description = current.description + paths + '\n';
				// Save the path for path vector
				path[edge.n2] = edge.description;

				pq.push(edge);

			}
		}
	}
	std::cout << distance[destination_node] << "\n";
	std::cout << path[destination_node] << "\n";
}

void Dijkstras::initNodes(node_id_t& start_node, node_id_t& destination_node) {
	std::cout << "Enter start node: \n";
	std::cin >> start_node;
	std::cout << "Enter destination node: \n";
	std::cin >> destination_node;
}