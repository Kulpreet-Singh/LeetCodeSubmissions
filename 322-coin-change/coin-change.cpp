class Solution {
public:
    int helper(int i, int t, vector<int>& coins, vector<vector<int>>& dp){
        if(t==0 || i==0){
            return (t%coins[0]==0)?(t/coins[0]):1e9;
        } 
        if(dp[i][t]!=-1) return dp[i][t];
        int notTake = helper(i-1, t, coins, dp);
        int take = 1e9;
        if(t>=coins[i]){
            take = 1+helper(i, t-coins[i], coins, dp);
        }
        return dp[i][t] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int ans = helper(coins.size()-1, amount, coins, dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};