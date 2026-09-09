class Solution {
private:
    int check( vector<int>& nums, int idx,vector<int>& dp){
        if(idx==0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx]+check(nums, idx-2,dp);
        int not_pick = check(nums, idx-1,dp);
        return dp[idx]= max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> a1;
        vector<int> a2;
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        for(int i=0;i<n;i++){
            if(i!=0) a1.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(i!=n-1) a2.push_back(nums[i]);
        }
        return max(check(a1,a1.size()-1,dp1), check(a2,a2.size()-1,dp2));
    }
};