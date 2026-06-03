class Solution {
private:
    bool check(vector<int>& arr, int n,int idx, int k, vector<vector<int>>& dp){
        if(idx==n) return 0;
        if(k==0) return 1;
        if(dp[idx][k]!=-1) return dp[idx][k];
        bool pick;
        if(arr[idx]<=k){
            pick = check(arr, n, idx+1, k-arr[idx],dp);
        }
        bool not_pick = check(arr,n,idx+1,k,dp);
        return dp[idx][k]= pick || not_pick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        if(n==1) return false;
        for(int i:nums) {
            sum +=i;
        }
        if(sum%2==1) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return check(nums,n,0,sum/2,dp);
    }
};