#include <bits/stdc++.h>
#include<unordered_set>
#include<vector>

using namespace std;


class Solution {
    public:

        bool isPossible(int i,const vector<int>&nums,vector<vector<int>> &memo,int target){
            if(target<0 ||i<0)
                return false;
            if (i == 0)
                return target == 0 || nums[0] == target;
            if(memo[i][target]!=-1){
                return memo[i][target] == 1;
            }

            bool notTaken = isPossible(i - 1, nums, memo, target);
            bool taken = false;
            if(target>=nums[i]){
                taken = isPossible(i - 1, nums, memo, target - nums[i]);
            }
            return memo[i][target] = (taken || notTaken) ? 1 : 0;
        }

        unordered_set<int> tracePath(const vector<int>&nums,vector<vector<int>>&memo,int target){
            unordered_set<int> visited;
            int sum = target;
            int n=nums.size()-1;
            
            while(sum>0 &&n>0){
                    if(sum-nums[n]>=0&&memo[n-1][sum-nums[n]]==1){
                        visited.insert(n);
                        sum -= nums[n];
                    }
                    n--;
                }
            return visited;
        }

        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(int n:nums){
                sum += n;
            }
            if(sum==0)return true;
            if(sum%2!=0)
                return false;

            vector<vector<int>> memo(nums.size(), vector<int>(sum / 2 + 1, -1));
            bool _1 = isPossible(nums.size()-1,nums, memo, sum / 2);
            if(!_1)
                return false;
            unordered_set<int> visited=tracePath(nums,memo,sum/2);
            vector<int> newNums;
            for (int i = 0; i < nums.size();i++)
            {
                if(visited.find(i)==visited.end()){
                    newNums.push_back(nums[i]);
                }
            }
            memo.resize(nums.size(), vector<int>(sum / 2 + 1, -1));
            bool _2 = isPossible(newNums.size()-1,newNums, memo, sum / 2);
            return _2 && _1;
        }
    };