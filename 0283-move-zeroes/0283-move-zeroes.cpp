class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()) {
            if(nums[r]!=0) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                
            }
           r++;
        }
    }
};