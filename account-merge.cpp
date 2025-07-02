
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<map>
#include "disjoint_set.cpp"
using namespace std;

class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            map<string, int> email_index;
            vector<vector<string>> result;
            disjoint_set ds(accounts.size());

            for (int i = 0; i < accounts.size();i++)
            {
                for (int j = 1; j < accounts[i].size();j++){
                    string email = accounts[i][j];
                    if (email_index.find(email) != email_index.end())
                    {
                        ds.union_set(i, email_index[email]);
                    }else{
                        email_index[email] = i;
                    }
                }
            }
            unordered_map < int, vector<string> >ref;


            for(const auto &[email,id]:email_index){
                ref[ds.find_parent(id)].push_back(email);
            }
            
            for(const auto &[id,emails]:ref){
                vector<string> temp;
                temp.push_back(accounts[id][0]);
                temp.insert(temp.end(),emails.begin(), emails.end());
                result.push_back(temp);
            }

            return result;
        }
    };