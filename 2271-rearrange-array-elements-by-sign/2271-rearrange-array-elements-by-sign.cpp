class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int neg=1,plus=0,n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
           if(nums[i]>0) {
            ans[plus] = nums[i];
            plus+=2;
           }
           else{
            ans[neg] = nums[i];
            neg += 2;
           }
        }
        return ans;
    }
};