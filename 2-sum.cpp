#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> ref;

        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(ref.find(temp) != ref.end()){
                return {ref[temp],i};
            }
            ref[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};