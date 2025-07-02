#include<iostream>
#include<vector>

using namespace std;


int helper(int cur,const vector<int>&height,vector<int> memo){
    if(cur<=0)
        return 0;
    if(memo[cur]!=-1)
        return memo[cur];
    int _1 = helper(cur-1,height,memo) +abs(height[cur]-height[cur-1]);
    int _2 = 1e9;

    if(cur-2>=0){
        _2 = helper(cur-2,height,memo) +abs(height[cur]-height[cur-2]);
    }
    return memo[cur]=min(_1,_2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> memo(n + 1, -1);
    return helper(n - 1, heights,memo);
}




//  for k jumps


int helper(int cur,int k,const vector<int>&height,vector<int>&memo){
    if(cur==0)
        return 0;
    if(memo[cur]!=-1)
        return memo[cur];
    int minJump = INT_MAX;

    for (int i = 1; i <= k;i++){
        if((cur-i)>0){   
            int cost = helper(cur - i, k, height, memo) + abs(height[cur] - height[cur - i]);
            minJump = min(minJump, cost);
        }
    }
    return memo[cur] = minJump;
}

int frogJump(int n,vector<int>&heights){
    vector<int> memo(n + 1, -1);
    return helper(n-1,2,heights,memo);
}

