class Solution {
public:
    // int helper(int i, int j, int& n, vector<vector<int>>& triangle,
    //            vector<vector<int>>& dp) {
    //     if (i == n) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     return dp[i][j] =
    //                triangle[i][j] + min(helper(i + 1, j, n, triangle, dp),
    //                                     helper(i + 1, j + 1, n, triangle, dp));
    // }

    // iterative approach
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=i; j>=0;j--){
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};