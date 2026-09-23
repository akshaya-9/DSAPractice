class Solution {
private:
int check(vector<int>& prices, int idx,int buy,int k, vector<vector<vector<int>>>& dp) {
    int profits=INT_MIN;
    if(k==0) return 0;
    if(idx==prices.size()) return 0;
    if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
    if(buy){
        profits = max(-prices[idx]+check(prices, idx+1,0,k,dp), check(prices, idx+1,1,k,dp));
    } else {
        profits = max(prices[idx]+check(prices, idx+1,1,k-1,dp), check(prices, idx+1,0,k,dp));
    }
    return dp[idx][buy][k]= profits;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return check(prices,0,1,2,dp);
    }
};