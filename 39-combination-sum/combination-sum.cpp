class Solution {
private:
    void comb(vector<int>& a,int k, vector<vector<int>>& ans, vector<int>& temp, int idx) {
        if(k==0) {
            ans.push_back(temp);
            return;
        }
        if(idx==a.size() || k<0){
            return;
        }
        temp.push_back(a[idx]);
        comb(a,k-a[idx],ans, temp,idx);
        temp.pop_back();
        comb(a,k,ans,temp,idx+1);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        comb(candidates, target, ans, temp,0);
        return ans;
    }
};