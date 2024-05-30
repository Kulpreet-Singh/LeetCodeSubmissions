class Solution {
public:
    string reverseWords(string s) {
        string output = "";
        int n = s.size();
        int i = n - 1;
        int j = i;

        while (i >= 0 && j >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            j = i;
            while (j >= 0 && s[j] != ' ') {
                j--;
            }
            output += s.substr(j + 1, i - j);
            i = j;
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i >= 0)
                output += ' ';
        }
        return output;
    }
};