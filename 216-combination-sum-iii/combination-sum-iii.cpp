class Solution {
private:
    void comb(int k, int n,int idx, vector<int>& temp, vector<vector<int>>& ans){
        if(n==0 && temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k || n<0) {
            return;
        }
        for(int i=idx;i<=9;i++){
            if(i<=n){
                temp.push_back(i);
                comb(k,n-i,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        comb(k,n,1,temp,ans);
        return ans;
    }
};