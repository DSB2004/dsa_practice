#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:

    void helper(int i,int j,vector<vector<char>>&board,vector<vector<bool>>& visited){
            int m=board.size();
            int n=board[0].size();
            if(i<0 ||j<0 ||i>=m||j>=n||visited[i][j]||board[i][j]!='O')return;
            visited[i][j]=true;
            board[i][j]='B';
            helper(i+1,j,board,visited);
            helper(i-1,j,board,visited);
            helper(i,j-1,board,visited);
            helper(i,j+1,board,visited);
            return;
        }

        void solve(vector<vector<char>>& board) {
            int m=board.size();
            int n=board[0].size();
            vector<vector<bool>>visited(m,vector<bool>(n));

            for (int i = 0; i < m; i++) {
                if (board[i][0] == 'O') {
                    helper(i, 0, board, visited);
                }
                if (board[i][n - 1] == 'O') {
                    helper(i, n - 1, board, visited);
                }
            }

            for (int j = 0; j < n; j++) {
                if (board[0][j] == 'O') {
                    helper(0, j, board, visited);
                }
                if (board[m - 1][j] == 'O') {
                    helper(m - 1, j, board, visited);
                }
            }



            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='B'){
                        board[i][j]='O';
                    }
                    else if(board[i][j]=='O'){
                        board[i][j]='X';
                    }
                }
    
            }
            return;
        }
    };