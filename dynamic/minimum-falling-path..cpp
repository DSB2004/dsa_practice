#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
        bool isValid(int n,int i){
            return i >= 0 && i < n;
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[n - 1].size();
            vector<int> prev(m);
            vector<int> cur(m);

            for (int i = 0; i < m;i++){
                prev[i] = matrix[0][i];
            }

            for (int i = 1; i < n;i++){
                for (int j = 0; j < m; j++)
                {
                    int d=INT_MAX,l = INT_MAX, r = INT_MAX;
                    d = prev[j] + matrix[i][j];
                    if(isValid(m,j-1))
                        l = prev[j-1] + matrix[i][j];
                    if(isValid(m,j+1))
                        r = prev[j+1] + matrix[i][j];
                    cur[j] = min(d, min(l, r));
                }
                prev = cur;
            }

            int _min = INT_MAX;
            for (int i = 0; i < m;i++){
                _min = min(cur[i],_min);
            }
            return _min;
        }
    };