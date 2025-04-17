class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();
        int l=0, r=n-1;
        while(l<r) {
            int width = r-l;
            int h = min(height[l], height[r]);
            ans = max(ans, (h*width));
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};