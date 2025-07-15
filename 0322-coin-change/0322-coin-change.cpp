class Solution {
private:
    int check(vector<int>& a, int amt, int idx, vector<vector<int>>& dp) {
        if(idx==0) {
            if(amt%a[0]==0) return amt/a[0];
            return 1e9;
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int not_pick = check(a,amt,idx-1 ,dp);
        int pick = 1e9;
        if(a[idx]<= amt) {
            pick = 1 + check(a, amt-a[idx], idx, dp);
        }
        return dp[idx][amt] = min(pick, not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans= check(coins, amount, n-1, dp);
        return (ans>=1e9) ? -1: ans;
    }
};