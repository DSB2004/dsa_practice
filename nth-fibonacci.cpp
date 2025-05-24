#include <bits/stdc++.h> 

int helper(int n,vector<long long> &memo){
    if(memo[n]!=-1) return static_cast<int>(memo[n]);
    if(n==1) return 1;
    memo[n] = static_cast<long long>(helper(n-1)) + static_cast<long long>(helper(n-2));
    return static_cast<int>(memo[n]);
    
}

int fibonacciNumber(int n){
    vector<long long> memo(n + 1, -1);
    memo[0] = 0;
    return helper(n,memo);
}