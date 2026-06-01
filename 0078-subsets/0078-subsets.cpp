class Solution {
private:
    void pwr(vector<int>& a, vector<int>& temp, vector<vector<int>>& ans, int idx){
        if(idx==a.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(a[idx]);
        pwr(a, temp, ans, idx+1);
        temp.pop_back();
        pwr(a,temp, ans, idx+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        pwr(nums, temp, ans, 0);
        return ans;
    }
};