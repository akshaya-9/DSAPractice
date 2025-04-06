class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int l=0, h=n-1;
        while(l<=h) {
            int mid =  (l+h)/2;
            if(a[mid] == target) return mid;
            else if(a[l]<= a[mid]) {
              if(a[l]<= target && target <= a[mid]) h = mid-1;
              else l = mid+1;
            } 
            else {
                if(a[mid]<=target && target <= a[h]) l=mid+1;
                else h= mid-1;
            }
        }
        return -1;
    }
};