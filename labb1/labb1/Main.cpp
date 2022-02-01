#include <iostream>
#include <vector>
#include "Reader.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Dijkstras.h"

int main() {
	// Grafen var inte sammanhängande för en nod avslutade med 19 3
	// och ingen nod hade 3 19
	setlocale(LC_ALL, "sv_SE.UTF-8");
	const std::string filename = "export.txt";

	// - Hur lång är vägen mellan Nackstavägen till Förrådet? Beskriv promenaden.
	// 23 1 2 3 4 5 6 7 8 10 28 37
	// Vikt 109.61

	// - Hur lång är vägen mellan L319 och D025?
	// 46 44 30 20 10 28 47
	// Vikt 32.25

    // - Hur lång är vägen från Universitetet till Bite Line Västra ?
	// 20 10 8 9 5 4 3 19
	// Vikt 81.7

	// datatyp: std::pair< map<int, std::string>, std::vector<edge> >
	adjacency_list_t list = parse_file(filename);
    //bfs(list);
	//dfs(list);
	Dijkstras dijk(list);

	return 0;
}