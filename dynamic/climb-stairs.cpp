#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int helper(int n,vector<int>memo){
            if (n <= 1) return 1;
            if (memo[n] != -1) return memo[n];
            return memo[n] = helper(n - 1, memo) + helper(n - 2, memo);

        }
        int climbStairs(int n) {
            vector<int> memo(n+1,-1);
            return helper(n,memo);
        }
    };