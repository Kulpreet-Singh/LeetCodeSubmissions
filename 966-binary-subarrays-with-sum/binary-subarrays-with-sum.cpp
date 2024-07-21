class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //hashing approach, works for both +ve and -ve numbers
        unordered_map<int, int> count;
        count[0] = 1;
        int currSum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(count.find(currSum - goal)!=count.end()){
                ans += count[currSum-goal];
            }
            count[currSum]++;
        }
        return ans;
    }
};