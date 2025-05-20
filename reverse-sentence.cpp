class Solution {
    public:
        string normalize(string s){
            string new_string;
            for(auto v:s){
                if(v==' ' && new_string.empty()) continue; // leading space
                else if (v==' ' && new_string.back()==' ') continue; // double space
                else {
                    new_string+=v;
                }
            }
            while(!new_string.empty()&&new_string.back()==' '){
                new_string.pop_back();
            }
            return new_string;
        }
        string reverseWords(string s) {
            
            s=normalize(s);
            reverse(s.begin(),s.end());
            int last=0;
            for(int i=0;i<s.size();i++){
                char v=s[i];
                if(v==' '){
                    reverse(s.begin()+last,s.begin()+i);
                    last=i+1;
                }
            }
            reverse(s.begin()+last,s.end());
            return s;
        }
    };