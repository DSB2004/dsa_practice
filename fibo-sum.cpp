
#include<iostream>
#include<vector>
using namespace std;


int fib(int n){
    const int MOD = 1e9 + 7;
    if(n == 0) return 0;
    if(n == 1) return 1;

    int a = 0,b=1;
    for(int i = 2; i <= n; ++i){
        int c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}
int fiboSum(int n,int m){

   const int MOD = 1e9 + 7;
    int sum=0;

    for(int i=n;i<=m;i++){
        sum=(sum+fib(i))%MOD;
    }
    return sum;
}



