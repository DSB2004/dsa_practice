class Solution {
public:
    void sortColors(vector<int>& nums) {
        int _0=0;
        int _1=0;
        int _2=0;

        for(auto v:nums){if(v==0)_0++;
        else if (v==1) _1++;
    else _2++;
}

for(int i=0;i<nums.size();i++){
    int marker=-1;
    if(_0>0){
        marker=0;
        _0--;
    }
     else if(_1>0){
        marker=1;
        _1--;
    }
    else{
        marker=2;
        _2--;
    }
    nums[i]=marker;

}
    }
};