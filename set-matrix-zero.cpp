#include<iostream>
using namespace std;

// // BRUTE FORCE SOLUTION  
// // Time Complexity: O[(n*m)+(n*m)] ~ O(n^2)
// // Space Complexity: O(n+m) 
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<vector<int>> temp;
//         int row_size=matrix.size();
//         if(row_size==0){
//             return;
//         }
//         int col_size=matrix[row_size-1].size();

//         for(int i = 0; i < row_size; i++)
//         {
//             for(int j=0;j<col_size;j++)
//             {
//                 if(matrix[i][j]==0){
//                     temp.push([i,j]);
//                 }
//             }
//         }


//         for(auto e:temp){
//             int row=e[0];
//             int col=e[1];

//             for(int i=0;i<col_size;i++){
//                 matrix[row][i]=0;
//             }
//             for(int i=0;i<row_size;i++){
//                 matrix[i][col]=0;
//             }
//         }
//         return;
//     }
// };


// BETTER SOLUTION  
// Time Complexity: O[(n*m)*(n+m)] ~ O(n^2)
// // Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if(row==0){
            return;
        }
        int col=matrix[row-1].size();

        bool isFirstRowZero=false;
        bool isFirstColZero=false;

        // check for first row and col
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                isFirstColZero=true;
            }
        }
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                isFirstRowZero=true;
            }
        }

        // Setting markers in first row and col
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][0]==0 ||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }


        if(isFirstColZero){
            for(int i=0;i<col;i++){
                matrix[0][i]=0;
            }
        }


        if(isFirstRowZero){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }

        return;
    }
};




