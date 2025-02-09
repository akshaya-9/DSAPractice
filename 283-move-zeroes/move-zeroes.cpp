class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), left=0, right=0;
        while(right<n) {
            if(nums[right]!=0) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right++;
            } else {
                right++;
            }
        }
    }
}; //O(N), O(1)