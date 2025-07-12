class Solution {
public:
    int check(vector<int>& nums, int idx, int last, vector<vector<int>>& dp) {
        if(idx==nums.size()) {
            return 0;
        }
        if(dp[idx][last+1]!=-1) return dp[idx][last+1]; 
        int take=0;
        if(last==-1 || nums[idx]>nums[last]) {
            take = 1+check(nums,idx+1,idx, dp);
        }
        int not_take = check(nums,idx+1,last,dp);
        return dp[idx][last+1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return check(nums, 0, -1, dp);
    }
};