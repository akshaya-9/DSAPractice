class Solution {
private:
    void comb(vector<int>& a, int k,vector<int>& temp,vector<vector<int>>& ans, int idx){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(idx==a.size() ||k<0){
            return;
        }
        temp.push_back(a[idx]);
        comb(a, k-a[idx],temp, ans, idx+1);
        temp.pop_back();
        for(int i=idx+1;i<a.size();i++){
            if(a[i]!=a[idx]){
            comb(a,k,temp,ans,i);
            break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        comb(candidates, target, temp, ans,0);
        return ans;
    }
};