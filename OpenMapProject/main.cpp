#include "IOStream.cpp"
#include "AStarAlgorithm.cpp"
#include <vector>
#include<iostream>
#include <windows.h>

using std::vector;

int main() {

    SetConsoleOutputCP(CP_UTF8);

    vector<vector<State>> board = ReadBoardFile("boardx.txt");

    int initial[2] = {17, 19};
    int goal[2] = {9, 17};
    auto solution = Search(board, initial, goal);
    PrintBoard(solution);
    

    return 0;
    
}