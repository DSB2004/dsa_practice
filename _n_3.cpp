class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int first=INT_MAX;
       int second=INT_MAX;
        int n=nums.size();
       int count1=0;
       int count2=0;

       for(auto num:nums){

        if(first==num)count1++;
        else if(second==num)count2++;
        else if (count1 == 0) {
            first = num;
            count1 = 1;
        } else if (count2 == 0) {
            second = num;
            count2 = 1;
        }
        else {count1--;count2--;}
        
       }

       count1=0;
       count2=0;

       for(auto num:nums){
        if(first==num)count1++;
        if(second==num)count2++;
       }

       if(count1>(n/3)) result.push_back(first);

       if(count2>(n/3)) result.push_back(second);

       return result;


    }
};