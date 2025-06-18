#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int m=image.size();
            int n=image[0].size();
            int originalColor = image[sr][sc];
            queue<pair<int,int>> _queue;
            vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};

            if (originalColor == color) return image;
            
            _queue.push({sr,sc});
            image[sr][sc]=color;
            
            while(!_queue.empty()){
                auto [r,c]=_queue.front();
                _queue.pop();
              
                    for (auto [dr, dc] : dir) {
                        int nr = r + dr;
                        int nc = c + dc;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&image[nr][nc]==originalColor) {
                            image[nr][nc] = color;
                            _queue.push({nr, nc});
                            
                        }
                    }
                
            }
            return image;
        }
    };