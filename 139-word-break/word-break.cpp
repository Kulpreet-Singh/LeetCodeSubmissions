class Solution {
public:
    bool helper(int j, string s, vector<string>& wordDict, vector<vector<int>>& dp) {
        if (s.size() == j) {
            return true;
        }
        bool ans = false;
        int maxSize = (s.size()-j<20)?(s.size()-j):20;
        for (int i = 1; i <= maxSize; i++) {
                    if(dp[j][i]!=-1) return dp[j][i];

            string substring = s.substr(j, i);
            for (string word : wordDict) {
                if (word == substring) {
                    ans = ans || helper(j+i, s, wordDict, dp);
                    if(ans) return dp[j][i] = ans;
                }
            }
            dp[j][i] = false;
        }
        return ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.size(), vector<int>(21, -1));
        return helper(0, s, wordDict, dp);
    }
};