#include <iostream>
#include <vector>
#include "Reader.h"
#include "Bfs.h"


int main() {
	const std::string filename = "export.txt";

	// Typ: std::pair< map<int, std::string>, std::vector<edge> >
	adjacency_list_t list = parse_file(filename);
	bfs(list);

	return 0;
}