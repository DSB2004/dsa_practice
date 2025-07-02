
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include "disjoint_set.cpp"
using namespace std;

using edge = vector<int>;
class Solution {
    private:
    string convertToString(vector<int> ref ){
        return to_string(ref[0]) + "," + to_string(ref[1]);
    }
    public:
        int removeStones(vector<vector<int>>& stones) {
            
            if(stones.size()==0)
                return 0;
            
            // get largest row and col
            int row = -1, col = -1;
            unordered_map<int, vector<edge>> row_vector;
            unordered_map<int, vector<edge>> col_vector;
            unordered_set<string> visited;

            for(const auto &stone:stones){
                row_vector[stone[0]].push_back({stone[0],stone[1]});
                col_vector[stone[1]].push_back({stone[0],stone[1]});
                row=max(row,stone[0]);
                col = max(col, stone[1]);
            }

            row++, col++;
            queue<pair<int,int>> ref;
            
            int count = 0;
            for (int i = 0; i < stones.size();i++){
                if(visited.find(convertToString(stones[i]))!=visited.end())
                    continue;
                count++;

                ref.push({stones[i][0], stones[i][1]});
                
                while(!ref.empty()){
                auto front = ref.front();
                ref.pop();
                int r = front.first;
                int c=front.second;
                if(visited.find(convertToString({r,c}))!=visited.end())
                    continue;
                visited.insert(convertToString({r,c}));
                    
              for(auto row:row_vector[r]){
                if(visited.find(convertToString({row[0],row[1]}))!=visited.end())
                    continue;
                ref.push({row[0],row[1]});

              }
              for(auto col:col_vector[c]){
                if(visited.find(convertToString({col[0],col[1]}))!=visited.end())
                    continue;
                ref.push({col[0],col[1]});
              }
           
            }   
        }
        return stones.size()-count;
        }


        // fuck this question
        int removeStones(vector<vector<int>>& stones) {
            
            if(stones.size()==0)
                return 0;
            int r = 0;
            int c = 0;
            for(const auto &stone:stones){
                r=max(r,stone[0]);
                c = max(c, stone[1]);
            }
            
            disjoint_set ds(r+c+1);
            unordered_set<int> check;
            for(const auto &stone:stones){
                int _r = stone[0];
                int _c = stone[1];
                check.insert(_r);
                check.insert(_c+r+1);
                ds.union_set(_r, _c+r+1);
            }
            int count = 0;
            for (int c:check){
                if(ds.find_parent(c)==c)
                    count++;
            }
            return stones.size()-count;
        }
    };