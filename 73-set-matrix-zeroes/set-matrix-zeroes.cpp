class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> columns;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(auto& it: rows){
            for(int j=0;j<n;j++){
                matrix[it][j] = 0;
            }
        }
        for(auto& it: columns){
            for(int i=0;i<m;i++){
                matrix[i][it] = 0;
            }
        }
    }
};