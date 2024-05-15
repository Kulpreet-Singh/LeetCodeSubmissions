class Solution {
public:
// hashing + heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        // hashing
        for(auto num: nums){
            mpp[num]++;
        }
        // max heap of the hashed values
        priority_queue<pair<int, int>> pq;
        for(auto &[key, value]: mpp){
            pq.push(make_pair(value, key));
        }
        // returing the top k elements
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};