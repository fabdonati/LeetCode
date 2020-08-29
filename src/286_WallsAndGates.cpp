/*
Medium

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
  */

#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) return;
        vector<vector<int>> empty_rooms;
        queue<vector<int>> queue_gates;

        int rows = rooms.size();
        int cols = rooms[0].size();
        
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                if (rooms[r][c]==0) queue_gates.push({r,c});
            }
        }

        while (!queue_gates.empty()) {
            
        }
        for (auto i : empty_rooms) {
            rooms[i[0]][i[1]] = min(calculateDistanceToGate(rooms, i[0], i[1], 0);
        }
    }
    int calculateDistanceToGate(vector<vector<int>>& rooms, int row, int col, int distance) {
        if (rooms[row][col] == 0) return distance;
        int rows = rooms.size();
        int cols = rooms[0].size();

        if (col>0)      calculateDistanceToGate(rooms, row  , col-1);
        if (col<cols-1) calculateDistanceToGate(rooms, row  , col+1);        
        if (row>0)      calculateDistanceToGate(rooms, row-1, col  );
        if (row<rows-1) calculateDistanceToGate(rooms, row+1, col  );        
    }
};