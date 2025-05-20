class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int _max=0;
            int count=0;
            for(auto num:nums){
                count=num==1?++count:0;
                _max=max(_max,count);
            }
            return _max;
        }
    };