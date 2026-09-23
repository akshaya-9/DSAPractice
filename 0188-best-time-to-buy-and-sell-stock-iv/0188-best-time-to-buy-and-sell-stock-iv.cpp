class Solution {
private:
    int check(int idx, int buy, int k,vector<int>& prices, int n, vector<vector<vector<int>>>& dp) {
        if(idx==n || k==0) return 0;
        int profits= INT_MIN;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        if(buy){
            profits = max(-prices[idx]+check(idx+1,0,k,prices,n,dp), check(idx+1,1,k,prices,n,dp));
        } else {
            profits = max(prices[idx]+check(idx+1,1,k-1,prices,n,dp), check(idx+1,0,k,prices,n,dp));
        }
        return dp[idx][buy][k]=profits;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return check(0,1,k,prices,n,dp);
    }
};