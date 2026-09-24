class Solution {
private:
    int check(string word1, string word2, int i,int j, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]= check(word1, word2, i-1,j-1,dp);
        else {
           return  dp[i][j]= min({1+check(word1,word2,i-1,j,dp),
                        1+check(word1,word2,i,j-1,dp),
                        1+check(word1, word2, i-1,j-1,dp)});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int i=word1.size();
        int j=word2.size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return check(word1,word2,i-1,j-1,dp);
    }
};