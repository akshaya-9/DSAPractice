class Solution {
public:
    int find_max(vector<int>& nums, vector<int>& dp,int i){
    if(i>= nums.size()){
        return 0;
    }
    if(dp[i] == -1){
        int take = nums[i] + find_max(nums, dp, i+2);
        int not_take = find_max(nums, dp, i+1); 
        dp[i] = max(take, not_take);
    }
    return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return find_max(nums, dp, 0);
    }
};