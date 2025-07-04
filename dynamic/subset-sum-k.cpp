#include <bits/stdc++.h> 
#include<unordered_set>
#include<vector>

using namespace std;


bool helper(int i,int k,const vector<int>&arr,vector<vector<int>> &memo){
    if(i<0)
        return false;  
    if(k==0 ||arr[i]==k)
        return true;
    if(memo[i][k]!=-1){
        return memo[i][k]==1;
    }

    bool not_included=helper(i -1, k, arr,memo);

    bool included = false;
    if(k>=arr[i]){
         included = helper(i -1,k-arr[i],arr,memo);
    }

    bool result=not_included || included;
    memo[i][k] = result ? 1 : 0;
    return result;
}



bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> memo(n,vector<int>(k+1,-1));
    return helper(n-1, k, arr,memo);
}



