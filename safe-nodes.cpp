#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<int>indegree(n,0);
            vector<vector<int>> reverse_list;
            queue<int> _queue;
            for(int i=0;i<n;i++){
                for(const edge:graph[i]){
                    reverse_list[edge].push_back(i);
                }
                if(graph[i].size()==0) _queue.push(i);
                indegree[i]=graph[i].size();
            }
            vector<int>result;

            while(!_queue.empty()){
                int front =_queue.front();
                _queue.pop();
                result.push_back(front);
                for(auto edge:reverse_list[front])
                    {
                        indegree[edge]--;
                        if(indegree[edge]==0){
                            _queue.push(edge);
                        }
                    }
                
                
            }
            sort(result.begin(),result.end());
            return result;
        }
};




// 0 -> [1,2]
// 1 -> [2,3]
// 2 -> [5]
// 3 -> [0]
// 4 -> [5]
// 5 -> []
// 6 ->[]



