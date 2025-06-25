
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    public:
    bool dfs(int node,vector<vector<int>> &list,vector<int> &vis,vector<int>& result){
        if(vis[node]==1) // visited
            return false;
        if(vis[node]==2) // course done
            return true;

        vis[node] = 1;

        for(const int edge:list[node]){
            if(!dfs(edge,list,vis,result))
                return false;
        }
        vis[node]=2;
        result.push_back(node);
        return true;
    }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            // first built the adjancy list
            vector<vector<int>> list(numCourses);
            for(const vector<int> &pre:prerequisites){
                int for_ = pre[0];
                int todo = pre[1];
                list[for_].push_back(todo);
            }
            vector<int> vis(0, numCourses);
            vector<int> result;

            for (int i = 0; i < numCourses;i++){
                if(vis[i]==0){
                    if(!dfs(i,list,vis,result)){
                        return {};
                    }
                }
            }
            // reverse(result.begin(), result.end());
            return result;
        }
        
    };