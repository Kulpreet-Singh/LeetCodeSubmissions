class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mpp;
        unordered_map<int, int> freq;

        int n = nums.size();
        int maxFreq = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            freq[num]++;
            if(mpp.find(num)==mpp.end()){
                mpp[num] = make_pair(i, i);
            }
            mpp[num].second = i;
            if(freq[num]>maxFreq){
                maxFreq = freq[num];
            }
        }
        int minLen = INT_MAX;
        for(auto it: freq){
            int size = it.second;
            if(size==maxFreq){
                int len = mpp[it.first].second - mpp[it.first].first + 1;
                if(len<minLen){
                    minLen = len;
                }
            }
        }
        return minLen;
    }
};