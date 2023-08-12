#include <iostream>
#include <sstream>
#include <fstream>

#include "IOStream.h"

using std::cout;
using std::ifstream;
using std::istringstream;

string CellString(State cell) {

    switch (cell)
    {
    
        case State::kObstacle : return "⛰️    ";

        case State::kStart : return "🚥  ";

        case State::kPath : return "🛩️   ";

        case State::kFinish : return "🏁   ";
        
        default: return "0    ";
    }

}


vector<State> ParseLine(string line) {

    istringstream board_row(line);
    
    vector<State> Row;
    int num;
    char ch;
    while (board_row >> num) {

        if (num == 0) {

            Row.emplace_back(State::kEmpty);

        } else {

            Row.emplace_back(State::kObstacle);

        }

        board_row >> ch;
    }

    return Row;
}

vector<vector<State>> ReadBoardFile (string path) {

    ifstream my_board(path);
    vector<vector<State>> Board;

    if (my_board) {

        string line;
        while (getline(my_board, line)) {

            Board.emplace_back(ParseLine(line));

        }

        my_board.close();

    } else {

        cout << "file not found!" << '\n';

    }

    return Board;
}


void PrintBoard(vector<vector<State>> &Board) {

    for (vector<State> row : Board) {
        
        for (State st : row) {

            cout << CellString(st);

        }

        cout << '\n';

    }

}
