#include<iostream>
#include <queue>
#include<vector>


using namespace std;

using _pair=pair<int,int>;

class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {

        queue<_pair> ref;
        ref.push({0,start});
        while(!ref.empty()){
            int size=ref.size();

            for(int i=0;i<size;i++){

                auto front=ref.front();
                int level=front.first;
                int node=front.second;
                if(node==end)return level;
                ref.pop();
                for(auto n:arr){
                    ref.push({level+1,(node*n)%100000});
                }
            }
        }
        return -1;
      }
     
  };
  