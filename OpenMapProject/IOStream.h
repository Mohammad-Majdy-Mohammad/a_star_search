#ifndef INPUT_STREAM_H
#define iNPUT_STREAM_H

#include "NodeState.cpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<vector<State>> ReadBoardFile (string path);
vector<State> ParseLine(string line);
string CellString(State cell);
void PrintBoard(vector<vector<State>> &Board);

#endif