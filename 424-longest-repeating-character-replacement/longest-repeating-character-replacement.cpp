class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int ans = 0;
        int maxf = 0; // freq
        int l = 0;
        int r = 0;

        for (int r = 0; r < s.size(); r++) {
            mpp[s[r]]++;
            maxf = max(maxf, mpp[s[r]]);
            int len = r - l + 1;
            if (len - maxf > k) {
                mpp[s[l]]--;
                l++;
            } else {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};