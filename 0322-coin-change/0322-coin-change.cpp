class Solution {
private:
    int compute(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp) {
        if(amount==0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(idx==0) {
            if(coins[idx]<=amount) {
            if(amount%coins[idx]==0) return dp[idx][amount]= amount/coins[idx];
            } 
            return 1e9+7;
        }
        int pick = 1e9+7;
        if(coins[idx]<=amount) {
            pick = 1+compute(coins, amount-coins[idx], idx,dp);
        }
        int not_pick = compute(coins, amount, idx-1,dp);
        return dp[idx][amount]= min(pick,not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= compute(coins, amount, coins.size()-1,dp);
        return (ans>=1e9+7)? -1: ans;
    }
};