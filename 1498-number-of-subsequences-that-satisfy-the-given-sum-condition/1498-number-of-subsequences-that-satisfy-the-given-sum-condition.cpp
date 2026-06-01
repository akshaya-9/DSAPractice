class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD=1e9+7;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,ans=0;
        vector<int> pow(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            pow[i] = (2LL*pow[i-1])%MOD;
        }
        while(l<=r) {
            if(nums[l]+nums[r]<=target) {
                ans = (ans+pow[r-l])%MOD;
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};