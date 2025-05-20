class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            // better approach

            // intuition would be first find the smallest one 
            // then compare each character with other
            // stops at the biggest one
            if(strs.size()==0)return strs[0];
            string smallest=strs[0];
            for(auto str:strs){
                if(str.size()<smallest.size()) smallest=str;
            }
            int result = 0;
            while (result < smallest.size()) {
                for (const auto& str : strs) {
                    if (str.substr(0, result + 1) != smallest.substr(0, result + 1)) {
                        return smallest.substr(0, result);
                    }
                }
                result++;
            }
        return smallest.substr(0, result);


        }


        // optimal solution 

        string longestCommonPrefix(vector<string>& strs){
            string s=strs[0];
            for(int i=1;i<strs.size();i++){
                int j=0;
                while(j<s.size()&&j<strs[i][j]&&s[j]==strs[i][j])j++;
                s=s.substring(0,j);
                if(s.size()==0) return s;
            }
            return s;
        }


    };