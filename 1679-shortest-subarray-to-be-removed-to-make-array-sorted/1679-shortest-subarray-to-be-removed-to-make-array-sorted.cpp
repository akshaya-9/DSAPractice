class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int l=0, n =a.size(), r=n-1, ans=0;
        while(r>0 && a[r]>=a[r-1]) {
            r--;
        }
        ans=r;
        while(l<r) {
            while(r<n && a[l]>a[r]) { r++; }
            ans = min(ans, r-l-1);
            l++;
            if(a[l]<a[l-1]) break;             
        }
        return ans;
    }
};