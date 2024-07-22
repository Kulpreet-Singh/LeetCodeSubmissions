class Solution {
public:
    void helper(int i, vector<int>& candidates, int target,
                vector<vector<int>>& result, vector<int>& path) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (i < 0) {
            return;
        }
        helper(i - 1, candidates, target, result, path);
        if (target >= candidates[i]) {
            path.push_back(candidates[i]);
            helper(i, candidates, target - candidates[i], result, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> path;
        helper(n - 1, candidates, target, result, path);
        return result;
    }
};