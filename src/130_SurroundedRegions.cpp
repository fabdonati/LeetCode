/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Example:

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
      if (board.size() == 0) return;
      int rows = board.size();
      int cols = board[0].size();
      vector<vector<int>> borders;

      // create a list of borders (as excaped cells will be surely on the border)
      for (int r=0; r<rows; r++) {  
        borders.push_back({r, 0});
        borders.push_back({r, cols-1});
      }
      for (int c=0; c<cols; c++) {
        borders.push_back({0, c});
        borders.push_back({rows-1, c});
      }

      // check on neighboring nodes i
      for (int i=0; i<borders.size(); i++) {
        callDFS(board, borders[i][0], borders[i][1]);
      }
      for (int r=0; r<rows; r++) {
        for (int c=0; c<cols; c++) {
          if (board[r][c]=='O') {
            board[r][c] = 'X';
          } else if (board[r][c]=='M') {
            board[r][c] = 'O';
          }
        }
      }
    }
  
  void callDFS(vector<vector<char>>& board, int r, int c) {
    int rows = board.size();
    int cols = board[0].size();
    
    if (board[r][c]!='O') return;
    
    board[r][c] = 'M';
    if (c<cols-1) callDFS(board, r  , c+1);
    if (c>0)      callDFS(board, r  , c-1);
    if (r<rows-1) callDFS(board, r+1, c  );
    if (r>0)      callDFS(board, r-1, c  );
  }
  
};