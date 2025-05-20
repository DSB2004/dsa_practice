class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n=nums.size();
            if(nums.size()==1||nums[0]!=nums[1]) return nums[0];
            if(nums[n-2]!=nums[n-1]) return nums[n-1];

            int i=1,j=n-2;

            while(i<=j){
                int mid = i + (j - i) / 2;
                if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];
                else if(mid%2==1 && nums[mid-1]==nums[mid]) i=mid+1;
                else if (mid%2==0 && nums[mid-1]==nums[mid]) j=mid-1;
                else if (mid%2==1 && nums[mid]==nums[mid+1]) j=mid-1;
                else i=mid+1;
            }
            return nums[j];
            
        }
    };