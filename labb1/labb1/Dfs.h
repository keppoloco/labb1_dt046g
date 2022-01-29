#pragma once
#ifndef DFS_H
#define DFS_H

#include "Dfs.h"
#include <stack>
#include "Reader.h"

struct stack {
	std::stack<node_id_t> data;

	node_id_t pop() {
		node_id_t node = data.top();
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

void push_and_visit(stack& s, node_id_t, std::vector<bool>&);
void dfs(const adjacency_list_t& list);
std::vector<node_id_t> unvisitedNeighbours(node_id_t curr_node, const adjacency_list_t& graph, std::vector<bool>& visited);
bool isVisited(node_id_t node, const std::vector<bool>& visited);
bool isAllVisited(const std::vector<bool>& visited);


#endif // ! DFS_H