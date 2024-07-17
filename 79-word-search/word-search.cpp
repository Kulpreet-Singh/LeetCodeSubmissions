class Solution {
public:
    bool helper(int i, int j, string word, vector<vector<char>>& board){
        if(word.size()==0){
            return true;
        }
        if(i<0 || j<0 || i>= board.size() || j >= board[0].size()){
            return false;
        }
        bool ans;
        if(board[i][j]==word[0]){
            board[i][j] = '0';
            string newWord = word.substr(1);
            ans = helper(i+1, j, newWord, board) ||
            helper(i-1, j, newWord, board) ||
            helper(i, j+1, newWord, board) ||
            helper(i, j-1, newWord, board);
            board[i][j] = word[0];
        } else {
            ans = false;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(helper(i, j, word, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};