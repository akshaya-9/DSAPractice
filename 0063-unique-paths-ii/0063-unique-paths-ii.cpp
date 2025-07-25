class Solution {
private:
    int check(vector<vector<int>>& grid, int i,int j, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 ||j>=m ||i>=n || grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = check(grid,i+1,j,dp) + check(grid,i,j+1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return check(obstacleGrid,0,0,dp);
    }
};