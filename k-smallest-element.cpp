#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;


int kthSmallest(int n,int k,vector<int> nums)
{

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

for(int i=0;i<count.size();i++){
                int num=count[i];
                sum_+=num;
                if(sum_>=k){
                    return i+min_;
                }
}
return -1;
        }


int kthSmallest(int n,int k,vector<int> nums)
{
    priority_queue<int> maxHeap;

    for(auto n:nums){
        maxHeap.push(n);
        if(maxHeap.size()>k)maxHeap.pop();
    }
    return maxHeap.top();
}
