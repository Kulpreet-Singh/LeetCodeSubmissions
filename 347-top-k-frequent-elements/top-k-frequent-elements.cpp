bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
class Solution {
public:
// hashing + heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        // hashing
        for(auto num: nums){
            mpp[num]++;
        }
        // convert hashMap to array and sort
        vector<pair<int, int>> hashArray(mpp.begin(), mpp.end());
        sort(hashArray.begin(), hashArray.end(), comparator);

        // returing the top k elements
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(hashArray[i].first);
        }
        return result;
    }
};