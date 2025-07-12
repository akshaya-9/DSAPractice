class Solution {
public:
    int cnt(int i, vector<int> dp) {
        if(i<=1) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cnt(i-1,dp) + cnt(i-2,dp);
    }
    int climbStairs(int n) {
     int prev2 =1,prev1=1 ,cur=0, ans=0;
     for(int i=2;i<=n;i++) {
         cur = prev2+prev1;
         prev2=prev1;
         prev1=cur;
     }
     return prev1;
    }
};