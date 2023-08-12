#ifndef A_STAR_ALGORITHM_H
#define A_STAR_ALGORITHM_H

#include <vector>
using std::vector;

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]);

int Heuristic(int, int, int, int);

void AddToOpen(int x, int y, int g_val, int h_val, vector<vector<int>> &openlist,
vector<vector<State>> &grid);

bool Compare(const vector<int> &nodeX, const vector<int> &nodeY);

void CellSort(vector<vector<int>> *openList);

bool CheckValidCell(int x, int y, vector<vector<State>> &grid);

void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &open, 
vector<vector<State>> &grid);

#endif