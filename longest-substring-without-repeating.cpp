class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ref;
        int result = 0;
        int l = 0, r = 0;

        while (r < s.size()) {
            if (ref.find(s[r]) == ref.end()) {
                ref.insert(s[r]);
                result = max(result, r - l + 1);
                r++;  
            } else {
                ref.erase(s[l]);  
                l++;  
            }
        }
        return result;
    }
};
