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
        vector<int> ahead(n+1, 0), cur(n+1, 0);
        for(int i=n-1;i>=0;i--){
            for(int j=i; j>=0;j--){
                cur[j] = triangle[i][j] + min(ahead[j], ahead[j+1]);
            }
            ahead = cur;
        }
        return ahead[0];
    }
};