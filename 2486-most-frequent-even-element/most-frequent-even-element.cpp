class Solution {
public:
// could have used hashing here
// but implementing a more optimised solution here
// Moore's Voting algo
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
                maxVal = it.second;
                mostFreqEle = min(mostFreqEle,it.first);
            } else if(maxVal<it.second){
                maxVal = it.second;
                mostFreqEle = it.first;
            }
        }
        return mostFreqEle;
    }
};