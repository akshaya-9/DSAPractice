class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> v;
        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if (sum == 0) {
                    v.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0) j++;
                else if (sum > 0) k--;
            } 
        }
        for(auto i: v) {
            res.push_back(i);
        }
        return res;
    }
};