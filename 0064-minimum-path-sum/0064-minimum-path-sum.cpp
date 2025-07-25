class Solution {
public:
    int check(vector<vector<int>>& grid,int i,int j, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 &&j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = grid[i][j]+ min(check(grid, i+1,j, dp) , check(grid,i,j+1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return check(grid, 0, 0,dp);
    }
};