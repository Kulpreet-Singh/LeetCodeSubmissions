class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int n = text1.length();
        int m = text2.length();
        vector<int> cur(m + 1, 0), prev(m + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};