#include <sstream>
#include <istream>
#include <fstream>
#include "Pathfinder.h"
using namespace std;

Pathfinder::Pathfinder() {
	for (int depth = 0; depth < DEPTH; depth++) 
	{
		for(int row = 0; row < ROW_SIZE; row++) 
		{
			for(int col = 0; col < COL_SIZE; col++) 
			{
				maze_grid[row][col][depth] = BACKGROUND;
			}
		}
	}
}

Pathfinder::~Pathfinder() {};

string Pathfinder::toString() const {
	stringstream ss;

	for (int depth = 0; depth < DEPTH; depth++) 
	{
		for(int row = 0; row < ROW_SIZE; row++) 
		{
			for(int col = 0; col < COL_SIZE; col++) 
			{
				ss << maze_grid[row][col][depth];
				if (col < COL_SIZE - 1) {ss << " ";}
			}
			/*if (!(depth == DEPTH - 1 && row == ROW_SIZE - 1)) {ss << endl;}*/
			ss << endl;
		}
		if(depth < DEPTH - 1) {ss << endl;}
	}
	return ss.str();
};

void Pathfinder::createRandomMaze() {
	srand(time(NULL));

	for (int depth = 0; depth < DEPTH; depth++) 
	{
		for(int row = 0; row < ROW_SIZE; row++) 
		{
			for(int col = 0; col < COL_SIZE; col++) 
			{
				maze_grid[row][col][depth] = rand() % 2;
			}
		}
	}
	maze_grid[0][0][0] = BACKGROUND;
	maze_grid[ROW_SIZE - 1][COL_SIZE - 1][DEPTH - 1] = BACKGROUND;
};

bool Pathfinder::importMaze(string file_name) {
	//cout << "importMaze from "<< file_name << endl;

		ifstream file (file_name.c_str());
		int tempMaze[ROW_SIZE][COL_SIZE][DEPTH];

		int tokencount = 0;
		if (file.is_open()) {
			string line;
			string temp;
			for (int depth = 0; depth < DEPTH; depth++) {
				for(int row = 0; row < ROW_SIZE; row++) {
					//if(getline(file, line)) rowcount++;}
					//stringstream ss(line);
					for(int col = 0; col < COL_SIZE; col++) {
						file >> temp;
						//if(file.eof()) return false;
						if (temp == "" || temp == "\n") return false;
						if (temp != "1" && temp != "0") {
							return false;
						}
						else {
							tokencount++;
						}
						//latest change
						tempMaze[row][col][depth] = stoi(temp);
						temp = "";
					}
				}
			}
		}
		else {
			return false;
		}

		//check for excess characters
		while (!file.eof()) {
			string temp;
			file >> temp;
			if (temp != " " && temp != "\n") {
				return false;
			}
		}
		//if (rowcount != ROW_SIZE * DEPTH - 1) return false;
		//cout << "ROWCOUNT" << rowcount << endl;
		cout << "TOKENCOUNT " << tokencount << endl;
		if(tokencount != ROW_SIZE * COL_SIZE * DEPTH) return false;

		if (tempMaze[0][0][0] == BACKGROUND && tempMaze[ROW_SIZE - 1][COL_SIZE - 1][DEPTH - 1] == BACKGROUND) {
			for (int depth = 0; depth < DEPTH; depth++) {
				for(int row = 0; row < ROW_SIZE; row++) {
					for(int col = 0; col < COL_SIZE; col++) {
						maze_grid[row][col][depth] = tempMaze[row][col][depth];
					}
				}
			}
		}
		else {
			return false;
		}

		return true;
};

vector<string> Pathfinder::solveMaze() {

}; //hi there