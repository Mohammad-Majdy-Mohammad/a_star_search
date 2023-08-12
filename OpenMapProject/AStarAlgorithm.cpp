   
#include <algorithm>
#include <iostream>
#include <vector>
#include "AStarAlgorithm.h"

using std::vector;
using std::sort;


    /*
    Search( grid, initial_point, goal_point ) :

        1.Initialize an empty list of open nodes.

        2.Initialize a starting node with the following:
            x and y values given by initial_point.
            g = 0, where g is the cost for each move.
            h given by the heuristic function (a function of the current coordinates and the goal).

        3.Add the new node to the list of open nodes.

        4.while the list of open nodes is nonempty:
            Sort the open list by f-value
            Pop the optimal cell (called the current cell).
            Mark the cell's coordinates in the grid as part of the path.

            if the current cell is the goal cell:
                return the grid.

            else, expand the search to the current node's neighbors. This includes the following steps:
                Check each neighbor cell in the grid to ensure that the cell is empty: it hasn't been closed and is not an obstacle.
                If the cell is empty, compute the cost (g value) and the heuristic, and add to the list of open nodes.
                Mark the cell as closed.

        5.If you exit the while loop because the list of open nodes is empty, you have run out of new nodes to explore and haven't found a path.
    */




// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};



vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {

    int h_val = Heuristic(init[0], init[1], goal[0], goal[1]);
    int g_val = 0;

    vector<vector<int>> open{};
    AddToOpen(init[0], init[1], g_val, h_val, open, grid);
    
    while (open.size() > 0)
    {
        CellSort(&open);

        // TODO: Get the x and y values from the current node,
        auto current = open.back();
        open.pop_back();
        int x = current[0];
        int y = current[1];
        // and set grid[x][y] to kPath.
        grid[x][y] = State::kPath;
        // TODO: Check if you've reached the goal. If so, return grid.
        if (x == goal[0] && y == goal[1]) {
            
            grid[init[0]][init[1]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
        
            return grid;
        }

        // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
        // ExpandNeighbors
        ExpandNeighbors(current, goal, open, grid);
        // TODO: End while loop
    }
    
    std::cout << "no path found" << '\n';
    
    return vector<vector<State>> {};
}


int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}



void AddToOpen(int x, int y, int g_val, int h_val, vector<vector<int>> &openlist,
vector<vector<State>> &grid) {
    
    vector<int> node = {x, y, g_val, h_val};
    openlist.emplace_back(node);
    grid[x][y] = State::kClosed;

}




bool Compare(const vector<int> &nodeX, const vector<int> &nodeY) {
    int f_valX = nodeX[2] + nodeX[3];
    int f_valY = nodeY[2] + nodeY[3];

    return f_valY < f_valX;
}


void CellSort(vector<vector<int>> *openList) {

    sort(openList->begin(), openList->end(), Compare);

}




bool CheckValidCell(int x, int y, vector<vector<State>> &grid) {

    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());

    if (on_grid_x && on_grid_y) 
        return grid[x][y] == State::kEmpty;
    
    return false;
}





/** 
 * Expand current nodes's neighbors and add them to the open list.
 */
void ExpandNeighbors(const vector<int> &current, int goal[2], vector<vector<int>> &open, 
vector<vector<State>> &grid) {

    int x = current[0];
    int y = current[1];

    for (int i = 0; i < 4; ++i) {
        
        int cell_x = x + delta[i][0];
        int cell_y = y + delta[i][1];
        
        if (CheckValidCell(cell_x, cell_y, grid)) {
            int g_val = current[2] + 1;
            int h_val = Heuristic(cell_x, cell_y, goal[0], goal[1]);
            AddToOpen(cell_x, cell_y, g_val, h_val, open, grid);
        }
    }
     
}