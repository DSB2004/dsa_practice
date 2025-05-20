class Solution {
    public:

        int num(char v){
            if (v=='I')return 1;
            if (v=='V')return 5;
            if (v=='X')return 10;
            if (v=='L')return 50;
            if (v=='C')return 100;
            if (v=='D')return 500;
            if (v=='M')return 1000;
            return 0;
        }
        int romanToInt(string s) {
            char last='-1';
            int value=0;
            for(auto v:s){
                if(last=='-1'){
                    value+=num(v);
                }
                else{
                    if(num(v)<=num(last)){
                        value+=num(v);    // VI -> 6  II -> 2   X1 -> 11   X11 -> 12
                     }
                    else{
                        value-=num(last);
                        value+=(num(v)-num(last));        // XIX -> 19
                    }
                }
                last=v;
            }
            return value;
        }
    };