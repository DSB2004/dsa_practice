class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int>ref1(26,0);
            vector<int>ref2(26,0);

            for(auto n:s){
                ref1[n-'a']++;
            }
            for(auto n:t){
                ref2[n-'a']++;
            }

            for(int i=0;i<26;i++){
                if(ref1[i]!=ref2[i]) return false;
            }
        return true;
        }
    };