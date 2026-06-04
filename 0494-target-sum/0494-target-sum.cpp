class Solution {
private:
    int ways(vector<int>& nums, int k,int idx) {
        if(idx==0) {
           if(k==0 && nums[0]==0) return 2;
           if(k==0 || nums[0]==k) return 1;
           return 0; 
        }
        int pick= 0;
        if(nums[idx]<=k){
            pick = ways(nums,k-nums[idx],idx-1);
        }
        int not_pick = ways(nums, k, idx-1);
        return pick+not_pick;
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
        return ways(nums, (sum-target)/2, n-1);
    }
};