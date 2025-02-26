class Solution{
public:
    int subarraySum(vector<int> &nums, int k){
        int ans=0, sum=0, n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum==k) {
                ans++;
            } 
            int rem = sum - k;
            if(m.find(rem)!=m.end()) {
                ans += m[rem];
            }
            m[sum]++;
        }
        return ans;
    }
};
