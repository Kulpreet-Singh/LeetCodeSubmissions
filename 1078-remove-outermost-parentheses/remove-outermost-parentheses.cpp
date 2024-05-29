class Solution {
public:
    string removeOuterParentheses(string s) {
        string output = "";
        int count = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (count != 0) {
                    output += ch;
                }
                count++;
            } else if (ch == ')') {
                count--;
                if (count != 0) {
                    output += ch;
                }
            }
        }
        return output;
    }
};