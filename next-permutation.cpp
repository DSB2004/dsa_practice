class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
        
        //  first calculate the number on right side that is smaller then the one on its right 
        int x=-1;
        for(int i=size-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                x=i; 
                break;
            } 
        }
        // now number smallest on right side but greater then x
        if(x>=0){
                int min_=size-1;
                for(int j=size-1;j>=0;j--){
                    if(nums[x]<nums[j]){
                        min_=j;
                        break;
                    }
                }
                swap(nums[x],nums[min_]);
        }
        reverse(nums.begin()+x+1,nums.end());
    }
};