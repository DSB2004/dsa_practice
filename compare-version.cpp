class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int i=0,j=0;

            while (i < version1.size() || j < version2.size()) {
                int _i = i, _j = j;

                while (i < version1.size() && version1[i] != '.') i++;
                string seg1 = version1.substr(_i, i - _i);
    
                while (j < version2.size() && version2[j] != '.') j++;
                string seg2 = version2.substr(_j, j - _j);
    
                int num1 = seg1.empty() ? 0 : stoi(seg1);
                int num2 = seg2.empty() ? 0 : stoi(seg2);
    
                if (num1 > num2) return 1;
                if (num1 < num2) return -1;
    
                // Skip the dots
                if(i<version1.size()){
                    i++;
                }
                else{
                    j++;
                }
            }

            return 0;
        }
    };