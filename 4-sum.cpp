class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>> result;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                
                int l=j+1;
                int r=n-1;

                while(l<r){
                    long long sum=nums[i]+nums[j]+nums[l]+nums[r];
                    if (sum==target){
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<n-1 &&nums[l]==nums[l+1]) l++;
                        while(r>0 && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if (sum<target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
                 }
            
        }
       return result;
    }
};