class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int result=0;
    
        while(i<g.size()&&j<s.size()){

            if(i<g.size()&&j<s.size() && g[i]<=s[j]){
                result++;
                i++;
            }
            j++;

        }
        return result;
    
    }
};