class Solution {
    public:
        string normalize(string s){
            string new_string;
            for(auto v:s){
                if(v==' ' && new_string.empty()) continue; 
                else {
                    new_string+=v;
                }
            }
          
            return new_string;
        }

        int myAtoi(string s) {
            s=normalize(s);
            bool isNeg=false;
            int n=s.size();
            long long value=0;
            int i = 0;

            if (i < n && s[i] == '-') {
                isNeg = true;
                i++;
            } else if (i < n && s[i] == '+') {
                i++; 
            }
    
            while(i<n&&isdigit(s[i])){
                char v=s[i];
                value*=static_cast<long long>(10);
                value+=static_cast<long long>(v-'0');
                i++;
                if (value > INT_MAX) return isNeg ? INT_MIN : INT_MAX;
            }
            
            return isNeg?-value:value;
        }
    };