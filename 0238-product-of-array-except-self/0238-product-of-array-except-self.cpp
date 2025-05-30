class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n,1);
        int prefix=1, postfix=1;
        for(int i=0; i<n; i++){
            ans[i] = prefix;
            prefix = prefix*nums[i];
            std::cout<<prefix<<std::endl;
        }
        for(int i= n-1;i>=0;i--) {
            ans[i] = ans[i]*postfix;
            postfix = postfix*nums[i];
        }
        return ans;
    }
};