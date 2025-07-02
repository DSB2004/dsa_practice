#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
        int helper(int n,int limit, const vector<int> &nums, vector<int> &memo)
        {
            if(n>=limit)
                return 0;

            if(memo[n]!=-1)
                return memo[n];

            int yes = nums[n] + helper(n + 2,limit, nums,memo);
            int no = helper(n + 1,limit,nums,memo);

            return memo[n]=max(yes, no);
        }
        int rob(vector<int>& nums) {
            int isFirst = false;
            vector<int> memo1(nums.size(), -1), memo2(nums.size(), -1);

            return max(helper(0, nums.size() - 2, nums, memo1), helper(1, nums.size() - 1, nums, memo2));
        }
    };