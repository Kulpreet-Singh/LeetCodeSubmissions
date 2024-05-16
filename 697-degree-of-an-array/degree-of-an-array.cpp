class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mpp;
        unordered_map<int, int> freq;

        int n = nums.size();
        int maxFreq = 0;
        // freq hash
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>maxFreq){
                maxFreq = freq[nums[i]];
            }
        }
        // if max freq, then maintain first and last index
        for(int i=0;i<n;i++){
            if(freq[nums[i]] == maxFreq){
                if(mpp.find(nums[i])==mpp.end()){
                    mpp[nums[i]] = make_pair(i, i);
                }
                mpp[nums[i]].second = i;
            }
        }
        // if maxFreq, then calculate minLen
        int minLen = INT_MAX;
        for(auto it: mpp){
            int len = it.second.second - it.second.first + 1;
            if(len<minLen){
                minLen = len;
            }
        }
        return minLen;
    }
};