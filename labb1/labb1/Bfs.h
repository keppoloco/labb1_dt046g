/*#pragma once
#ifndef BFS_H
#define BFS_H

#include "Reader.h"
#include <iostream>
#include <string>
#include <queue>

struct queue {
	std::queue<node_id_t> data;

	node_id_t pop() {
		node_id_t node = data.front();
		data.pop();
		return node;
	}

	void push(node_id_t node_id) {
		data.push(node_id);
	}
	size_t size() {
		return data.size();
	}
};

void push_and_visit(queue&, node_id_t, std::vector<bool>& visited);
void bfs(const adjacency_list_t& list);
std::vector<node_id_t> unvisitedNeighbours(node_id_t curr_node,  const adjacency_list_t& graph, std::vector<bool>& visited);
bool isVisited(node_id_t node, const std::vector<bool>& visited);
bool isAllVisited(const std::vector<bool>& visited);


#endif*/