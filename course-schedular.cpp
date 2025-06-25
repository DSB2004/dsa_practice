
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
using namespace std;


class Solution {
    public:

        bool dfs(int node,vector<vector<int>> &list,vector<int>&visited){
            if(visited[node]==1)
                return false;
            if(visited[node]==2)
                return true;
            
            visited[node]=1;

            for(auto const edge:list[node]){
                if(!dfs(edge,list,visited))
                    return false;
            }
            visited[node] = 2;
        }


        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

            vector<vector<int>> list(numCourses);

            for(auto const &prerequisite:prerequisites){
                list[prerequisite[1]].push_back(prerequisite[0]);
            }
    
  
            vector<int> visited(numCourses,0);

            for (int i = 0; i < numCourses;i++){
                if(visited[i]!=0) continue;
                if(!dfs(i,list, visited))
                    return false;
            }

            return true;
        }
    };