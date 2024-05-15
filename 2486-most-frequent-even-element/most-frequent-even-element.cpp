class Solution {
public:
// hashing 
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto num: nums){
            if(num%2==0){
                mpp[num]++;
            }
        }
        int maxVal = 0;
        int mostFreqEle = -1;
        for(auto it: mpp){
            if(maxVal==it.second){
                mostFreqEle = min(mostFreqEle,it.first);
            } else if(maxVal<it.second){
                maxVal = it.second;
                mostFreqEle = it.first;
            }
        }
        return mostFreqEle;
    }
};