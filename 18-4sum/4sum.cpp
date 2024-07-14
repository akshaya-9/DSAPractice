class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0; i < nums.size(); i++) {
            for(int j=i+1; j < nums.size(); j++) {
                int k = j + 1, l = nums.size()-1;
                while(k<l) {
                    long long  sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + 
                        (long long)nums[l];
                    if(sum == target) {
                        v.insert({nums[i],nums[j],nums[k], nums[l]});
                        k++;
                        l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        for(auto i: v) {
            res.push_back(i);
        }
    return res;
    }
};