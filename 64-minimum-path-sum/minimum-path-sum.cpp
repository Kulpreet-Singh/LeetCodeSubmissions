class Solution {
public:
    // int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i==0 && j==0){
    //         return grid[0][0];
    //     }
    //     if(i<0 || j<0){
    //         return 1e9;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans = grid[i][j] + min(helper(i-1, j, grid, dp), helper(i, j-1, grid, dp));
    //     return dp[i][j] = ans;
    // }

// iterative approach
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        prev[0] = grid[0][0];
        for(int j=1;j<n;j++){
            prev[j] = prev[j-1] + grid[0][j];
        }
        for(int i=1; i<m;i++){
            prev[0] = prev[0] + grid[i][0];
            for(int j=1;j<n;j++){
                prev[j] = grid[i][j] + min(prev[j], prev[j-1]);
            }
        }
        return prev[n-1];
    }
};