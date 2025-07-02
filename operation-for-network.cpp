#include<vector>
#include<queue>
#include<iostream>

using namespace std;


class disjoint_set{

    vector<int> rank;
    vector<int> par;

    public:
    disjoint_set(int n){
        rank.resize(n, 0);
        par.resize(n);
        for (int i = 0; i <n; i++)
        {
            par[i] = i;
        }
    }

    public:
    
    int find_par(int u){
        if(u==par[u]) return par[u];
        return par[u]=find_par(par[u]);
    }

    void union_set(int u,int v){
        int p_u = find_par(u);
        int p_v = find_par(v);

        if(p_u==p_v)
            return;
        
        if(rank[p_u]>rank[p_v]){
            par[p_v] = p_u;
        }
        else if(rank[p_v]>rank[p_u]){
            par[p_u] = p_v;
        }
        else{
            par[p_v] = p_u;
            rank[p_u]++;
        }
    }

};


class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            int cycle_found = 0;
            if(connections.size()<n-1)
                return -1;
            disjoint_set ds(n);
            for(const auto&connection:connections){
                if(ds.find_par(connection[0])==ds.find_par(connection[1])){

                    cycle_found++;
                }
                else{
                    ds.union_set(connection[0], connection[1]);
                
                }
            }
            int disconnected_components = 0;

            for (int i = 0; i < n;i++){
                if(ds.find_par(i)==i){
                    disconnected_components++;
                }
            }
            return cycle_found >= disconnected_components - 1?cycle_found:-1;
        }   
    };