#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include "disjoint_set.cpp"


class disjoint_set{

    private:
    int size = 0;
    vector<int> rank;
    vector<int> par;

    public:
    disjoint_set(int size){
        this->size=size+1;
        this->rank.resize(this->size,0);
        this->par.resize(this->size);
        for (int i = 0; i < this->size; ++i) {
            this->par[i] = i;
        }
    }

    bool union_set(int u,int v){

        int p_u = find_parent(u);
        int p_v = find_parent(v);


        if(p_u==p_v)
            return false;
        int r_p_u = rank[p_u];
        int r_p_v = rank[p_v];

        if(r_p_u==r_p_v){
            par[p_v] = par[p_u];
            rank[p_u]++;
        }
        else if(r_p_u>r_p_v){
            par[p_v] = par[p_u];
        }  else {
            par[p_u] = par[p_v];
        }
        return true;
    }

    int find_parent(int u) {
        if (u == par[u]) return u;
        return par[u] = find_parent(par[u]);
    }

    bool  same_set(int u,int v) {
       return  find_parent(u) == find_parent(v);
    }
};

class Solution {
    public: 
    int returnComponent(int n,int m,vector<vector<int>>grid){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> ref;
        int count = 0;
        vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m; j++)
            {
                if(vis[i][j] ||grid[i][j]==0)continue;
                count++;
                ref.push({i, j});
                while(ref.empty()){
                    auto front = ref.front();
                    ref.pop();
                    int r = front.first;
                    int c = front.second;
                    if(vis[r][c])continue;
                    vis[r][c]=true;
                    for(const auto &dir:dirs){
                        int nr=r+dir.first;
                        int nc = c + dir.second;
                        if (nr >= 0 && nr<n &&nc>=0&&nc<m&&!vis[nr][nc] && grid[nr][nc]==1){
                            ref.push({nr, nc});
                        }
                    }
                }
            }
        }
        return count;
    }
      vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
          vector<vector<int>> grid(n, vector<int>(m, 0));
          vector<int> result;
          for(const auto &op:operators){
              grid[op[0]][op[1]] = 1;
              result.push_back(returnComponent(n, m, grid));
          }
          return result;
      }

      int returnNode(int offset,int r,int c){
          return offset * r + c;
      }
      vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> result;
        int count=0;
        disjoint_set ds(m *n+1);
        vector<pair<int,int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        
        for(const auto &op:operators){
            int r = op[0];
            int c = op[1];

            int node = returnNode(m, r, c);
            
            if(grid[r][c]==1){
                // to cover duplicate operations
                result.push_back(count);
                continue;
            }
            grid[r][c] = 1;
            count++;
            for(const auto &dir:dirs){
                int nr=r+dir.first;
                int nc = c + dir.second;
                if (nr >= 0 && nr<n &&nc>=0&&nc<m&& grid[nr][nc]==1){
                    int _node = returnNode(m, nr, nc);
                    if(ds.union_set(node, _node))
                        count--;

                }
            }
            result.push_back(count);
        }
        return result;
    }
  };
  