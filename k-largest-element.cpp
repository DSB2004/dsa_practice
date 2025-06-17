#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int,vector<int>,greater<int>> heap;
            for(auto n:nums){
                heap.push(n);
                if(heap.size()>k)heap.pop();
            }
            return heap.top();
        }


        int findKthLargest(vector<int>&nums,int k){
            // using count sort 

            int min_=INT_MAX;
            int max_=INT_MIN;
            for(auto num:nums){
                min_=min(min_,num);
                max_=max(max_,num);
            }

            vector<int> count(max_-min_+1,0);

            for(auto num:nums){
                count[num-min_]++;
            }

            int sum_=0;

            for(int i=count.size()-1;i>=0;i--){
                int num=count[i];
                sum_+=num;
                if(sum_>=k){
                    return i+min_;
                }
            }
            return -1;
        }
    };