class Solution {
public:
    // sliding window approach, works only because the values are positive
    int numSubarraysWithLessThanEqualsSum(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int count = 0;
        for (r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            if (sum <= goal) {
                count += r - l + 1;
            }
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // hashing approach, works for both +ve and -ve numbers
        //  unordered_map<int, int> count;
        //  count[0] = 1;
        //  int currSum = 0;
        //  int ans = 0;
        //  for(int i=0;i<nums.size();i++){
        //      currSum += nums[i];
        //      if(count.find(currSum - goal)!=count.end()){
        //          ans += count[currSum-goal];
        //      }
        //      count[currSum]++;
        //  }
        //  return ans;

        return numSubarraysWithLessThanEqualsSum(nums, goal) -
               numSubarraysWithLessThanEqualsSum(nums, goal - 1);
    }
};