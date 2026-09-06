class Solution {
private:
    bool check(vector<int>& nums, int m,int k,int mid){
        int count=0,bou=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                if(count==k){
                    count=0;
                    bou++;
                }
            } else {
                count=0;
            }
            if(bou==m){
                return true;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        int l=0, ans=-1;
        int h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = (l+h)/2;
            if(check(nums, m,k,mid)) {
               ans= mid;
               h=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};