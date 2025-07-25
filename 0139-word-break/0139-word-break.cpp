class Solution {
public:
    bool check_word(int l, int r, string s, unordered_set<string>& words,  vector<vector<int>>& dp) {
        if(r>s.length()) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        if(words.find(s.substr(l, r-l)) != words.end()) {
            if(r==s.length() || check_word(r,r+1,s,words, dp)) return dp[l][r] = 1;
        }
        return dp[l][r] = check_word(l,r+1,s,words, dp);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int l=0,r=0;
        int n =s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return check_word(l,r+1,s, words, dp);    
    }
};