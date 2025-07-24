class Solution {
public:
    int findMin(vector<int>& a) {
        int ans=INT_MAX;
        int n= a.size();
        int l=0,h=n-1;
        while(l<=h) {
            int mid = (l+h)/2;
            if(a[l]==a[mid] && a[mid]==a[h]) {
                ans =min(ans, a[mid]);
                l++;
                h--;
                continue;
            }
            if(a[l]<=a[mid]) {
                ans = min(ans, a[l]);
                l=mid+1;
            }
            else {
                ans =min(ans,a[mid]);
                h=mid-1;
            }
        }
        return ans;
    }
};