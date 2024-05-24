class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        long long val = 1;
        for(int j=0;j<rowIndex;j++){
            val = val * (rowIndex - j);
            val = val / (j+1);
            row.push_back((int) val);
        }
        return row;
    }
};