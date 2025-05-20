class Solution {
    public:
        string longestPalindrome(string s) {

            string r=s;
            reverse(r.begin(),r.end());


            int count=0;
            int _max=0;

            for(int i=0;i<s.size();i++){
                if(s[i]==r[i]){
                    count++;
                }
                else{
                    count=0;
                }
                _max=max(_max,count);
            }
            return _max;
        }

    };