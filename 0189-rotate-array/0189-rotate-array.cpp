class Solution {
private:
    void reverse(vector<int>& nums, int begin, int end){
        while(begin<end) {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0 , k-1);
        reverse(nums, k, n-1);
    }
};