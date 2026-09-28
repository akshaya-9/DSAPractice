class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmax=0,curmin=0, total=0;
        int maxSum=nums[0],minSum=nums[0];
        for(int i=0;i<nums.size();i++){
            curmax =max(nums[i],nums[i]+curmax);
            maxSum = max(maxSum,curmax);
            curmin = min(nums[i],nums[i]+curmin);
            minSum=min(minSum,curmin);
            total += nums[i];
        }
        return maxSum>0 ? max(maxSum,total-minSum) : maxSum;
    }
};