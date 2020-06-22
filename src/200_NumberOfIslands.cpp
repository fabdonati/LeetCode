#include <vector>
#include <iostream>
// BFS

using namespace std;
void callBFS(vector<vector<int>> &grid, int i, int j) { // pass by reference because we need to modify it
    if (i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] == 0) { 
        return;
    }
    grid[i][j] = 0;
    callBFS(grid, i+1, j);
    callBFS(grid, i-1, j);
    callBFS(grid, i, j-1);
    callBFS(grid, i, j+1);
}

int main() {
    int count = 0;
    vector<vector<int>> grid{{1,1,0,0,0},
                             {1,1,0,0,0},
                             {0,0,1,0,0},
                             {0,0,0,1,1}};
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if(grid[i][j]==1) {
                count++;
                callBFS(grid, i, j);
            }
        }
    }
    std::cout << count << std::endl;
    return count;
}