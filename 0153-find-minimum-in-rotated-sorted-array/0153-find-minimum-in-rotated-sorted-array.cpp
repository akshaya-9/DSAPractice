class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l = 0, h=n-1, ans = INT_MAX;
        while(l<=h) {
            int mid = (l+h)/2;
            if(a[l] <= a[mid]) {
                ans = min(ans, a[l]);
                l = mid+1;
            } else {
                ans = min(ans, a[mid]);
                h = mid-1;
            }
        }
        return ans;
    }
};