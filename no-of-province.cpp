
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n=isConnected.size();
            if(n==0)return n;
            vector<bool> visited(n,false);
            int result=0;
            for(int i=0;i<n;i++){
                stack<int> _stack;
                if(visited[i]) continue;
                _stack.push(i);
                while(!_stack.empty()){
                    int top=_stack.top();
                    _stack.pop();
                    visited[top]=true;
                    for(int i=0;i<n;i++){
                        if(isConnected[top][i]==1 && !visited[i]){
                            _stack.push(i);
                        }
                    }
                }
                result++;
            }

            return result;

        }
    };