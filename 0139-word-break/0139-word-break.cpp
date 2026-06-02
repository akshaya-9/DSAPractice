class Solution {
private:
    bool func(string s, unordered_set<string>& dict, int start, vector<int>& dp) {
        if(start==s.length()) return 1;
        if (dp[start]!= -1) return dp[start];
        for(int end=start+1;end<=s.length();end++){
            string word =s.substr(start,end-start);
            if((dict.find(word)!=dict.end()) && func(s,dict,end,dp)) {
                return dp[start] = 1;
            }
        }
        return dp[start]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length(),-1);
        return func(s,dict,0,dp);
    }
};