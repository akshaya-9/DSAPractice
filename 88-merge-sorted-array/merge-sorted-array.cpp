class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int left = n-1, right = m-1;
        int idx= n+m-1;
        while(left>=0 && right>=0) {
            std::cout<<nums1[left] <<" --  "<<nums2[right]<<std::endl;
            if(nums1[left] > nums2[right]) {
                nums1[idx] = nums1[left];
                left--;
            }
            else {
                nums1[idx] = nums2[right];
                right--;
            }
            idx--;
        }
        while(right>=0) {
            nums1[idx] = nums2[right];
            right--;
            idx--;
            
        }
    }
};