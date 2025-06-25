#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> color(n,-1);
            for (int i = 0; i < n;i++){
                if (color[i] != -1)
                    continue;
                color[i] = 0;
                queue<int> ref;
                ref.push(i);

                while (!ref.empty())
                {
                    int top = ref.front();
                    ref.pop();
                    int parentColor = color[top];
                    int colorToAssign = parentColor == 0 ? 1 : 0;
                    vector<int> edges = graph[top];
                    for (const auto &edge : edges)
                    {
                        if (color[edge] == -1)
                        {
                            color[edge] = colorToAssign;
                            ref.push(edge);
                        }
                        else if (color[edge] == parentColor)
                        return false;
                        
                    }
                }
                    
        }
        return true;
    }
};