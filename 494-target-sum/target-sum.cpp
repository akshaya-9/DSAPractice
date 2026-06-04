class Solution {
private:
    int ways(vector<int>& nums, int k,int idx,vector<vector<int>>& dp) {
        if(idx==0) {
           if(k==0 && nums[0]==0) return 2;
           if(k==0 || nums[0]==k) return 1;
           return 0; 
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        int pick= 0;
        if(nums[idx]<=k){
            pick = ways(nums,k-nums[idx],idx-1,dp);
        }
        int not_pick = ways(nums, k, idx-1,dp);
        return dp[idx][k]=pick+not_pick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;;
        for(int i:nums) {
            sum += i;
        }
        int n=nums.size();
        if(sum-target<0) return 0;
        if((sum-target)%2==1) return 0;
        int req =(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(req+1,-1));
        return ways(nums, req, n-1,dp);
    }
};