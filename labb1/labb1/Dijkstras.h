#pragma once
#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H
#include <queue>
#include "Reader.h"

template<>
struct std::less<edge> {
	bool operator()(const edge& e1, const edge& e2) {
		return e1.weight < e2.weight;
	}
};

class Dijkstras {
public:
	Dijkstras(const adjacency_list_t&);
	void initNodes(node_id_t&, node_id_t&);
	edge getSource(const adjacency_list_t& graph, const node_id_t node);
	std::string getNodeName(const adjacency_list_t& graph, const node_id_t node);
private:
	std::priority_queue<edge> pq;
	std::vector<edge> adjacentNodes(const adjacency_list_t&, const edge&);
};





#endif // !DIJKSTRAS_H
