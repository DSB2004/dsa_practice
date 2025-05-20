#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        if(numRows==0){return result;}

        
        result.push_back({1});
        for(int i=1;i<numRows;i++){

            vector<int> prev = result.back(); 
            vector<int> current;

            current.push_back(1);
            for(int i=1;i<prev.size();i++){
                current.push_back(prev[i-1]+prev[i]);
            }
            current.push_back(1);
            result.push_back(current);
        }
        
        return result;
        
    }
};