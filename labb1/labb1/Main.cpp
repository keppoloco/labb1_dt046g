#include <iostream>
#include <vector>
#include "Reader.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Dijkstras.h"

int main() {
	// Grafen var inte sammanh�ngande f�r en nod avslutade med 19 3
	// och ingen nod hade 3 19
	setlocale(LC_ALL, "sv_SE.UTF-8");
	const std::string filename = "export.txt";

	// - Hur l�ng �r v�gen mellan Nackstav�gen till F�rr�det? Beskriv promenaden.
	// 23 1 2 3 4 5 6 7 8 10 28 37
	// Vikt 109.61

	// - Hur l�ng �r v�gen mellan L319 och D025?
	// 46 44 30 20 10 28 47
	// Vikt 32.25

    // - Hur l�ng �r v�gen fr�n Universitetet till Bite Line V�stra ?
	// 20 10 8 9 5 4 3 19
	// Vikt 81.7

	// datatyp: std::pair< map<int, std::string>, std::vector<edge> >
	adjacency_list_t list = parse_file(filename);
    //bfs(list);
	//dfs(list);
	Dijkstras dijk(list);

	return 0;
}