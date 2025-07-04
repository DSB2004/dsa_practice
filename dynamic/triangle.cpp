#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
    int helper(int level,int cur,vector<vector<int>>&memo,const vector<vector<int>> &triangle){
        if (level >= triangle.size())
            return 0;
        if(memo[level][cur]!=INT_MIN)
            return memo[level][cur];

        memo[level][cur] = triangle[level][cur] + min(helper(level + 1, cur, memo, triangle), helper(level + 1, cur + 1, memo, triangle));
        return memo[level][cur];
    }
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int m = triangle[0].size();
            vector<vector<int>> memo(n, vector<int>(n, INT_MIN));

            return helper(0, 0, memo, triangle);
        }
    };