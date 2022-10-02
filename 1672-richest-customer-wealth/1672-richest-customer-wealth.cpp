class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
     int ans=INT_MIN,maxi;
        for(int i=0;i<accounts.size();i++){
            maxi=0;
            for(int j=0;j<accounts[0].size();j++){
                maxi = maxi + accounts[i][j];
            }
            ans = max(ans,maxi);
        }
        return ans;
    }
};

//TC:O(N^2) , SC:O(1)