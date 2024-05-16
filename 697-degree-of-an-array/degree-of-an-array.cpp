class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        int maxFreq = 0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(mpp.find(num)==mpp.end()){
                mpp[num] = {};
            }
            mpp[num].push_back(i);
            if(mpp[num].size()>maxFreq){
                maxFreq = mpp[num].size();
            }
        }
        int minLen = INT_MAX;
        for(auto it: mpp){
            int size = it.second.size();
            if(size==maxFreq){
                int len = it.second.back() - it.second.front() + 1;
                if(len<minLen){
                    minLen = len;
                }
            }
        }
        return minLen;
    }
};