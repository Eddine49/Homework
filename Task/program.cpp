#include <iostream>
#include <string>
#include <fstream>
#include "game_of_life.h"
using namespace std;

int main() {

	game_of_life the_game;

	vector<vector<int>> matrix = the_game.generateMatrix(20, 20);
	/*vector<vector<int>> matrix = {
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,1,0,0,0,0,0},
 {0,0,0,1,1,1,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}
	};*/

	bool again;
	do {
		the_game.draw(matrix);

		the_game.next_generation(matrix);

		cout << "Again (1/0): ";
		cin >> again;
	} while (again);

	return 0;
}