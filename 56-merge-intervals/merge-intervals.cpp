bool comparator(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0, j = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> result;
        while (i < n) {
            j = i + 1;
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (j < n && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }
            result.push_back({start, end});
            i = j;
        }
        return result;
    }
};