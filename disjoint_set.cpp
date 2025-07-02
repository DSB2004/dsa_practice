#include<vector>
#include<iostream>

using namespace std;




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

    void union_set(int u,int v){

        int p_u = find_parent(u);
        int p_v = find_parent(v);


        if(p_u==p_v)
            return;
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


    }

    int find_parent(int u) {
        if (u == par[u]) return u;
        return par[u] = find_parent(par[u]);
    }

    bool  same_set(int u,int v) {
       return  find_parent(u) == find_parent(v);
    }
};


int main(){
    disjoint_set _set(7);
    _set.union_set(1, 2);
    _set.union_set(2, 3);
    _set.union_set(4, 5);
    _set.union_set(6, 7);
    _set.union_set(5, 6);
    _set.union_set(1, 2);

    // few checks

    cout << "Do 3 and 7 belong to same parent -> "<<(_set.same_set(3,7))<<endl;
    _set.union_set(3, 7);
    cout << "Do 3 and 7 belong to same parent -> "<<(_set.same_set(3,7))<<endl;
    return 0;
}