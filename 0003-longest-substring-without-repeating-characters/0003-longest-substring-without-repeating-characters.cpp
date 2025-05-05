class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        int n =s.length();
        set<char> set;
        while(r<n) {
            if(set.find(s[r])==set.end()) {
                ans = max(ans,r-l+1);
                set.insert(s[r]);
                r++;
            } else {
               set.erase(s[l]);
               l++;
            }
         }
        return ans;
    }
};