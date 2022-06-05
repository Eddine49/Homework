
#pragma once



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class game_of_life {
public:
	
	void next_generation(vector<vector<int>>& matrix);
	void draw(vector<vector<int>>& matrix);
	vector<vector<int>> generateMatrix(int columns, int rows);

};



