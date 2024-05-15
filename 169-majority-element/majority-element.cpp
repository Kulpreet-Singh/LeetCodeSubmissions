class Solution {
public:
// optimal approach
// Moore’s Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int exceedingCount = 0;
        int majorityElement = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(exceedingCount ==0){
                exceedingCount = 1;
                majorityElement = nums[i];
            } else if(majorityElement == nums[i]){
                exceedingCount++;
            } else {
                exceedingCount--;
            }
        }
        // case to validate in case this is not an actual majority
        int cnt = 0;
        for(auto it: nums){
            if(it==majorityElement) 
                cnt++;
        }
        if(cnt>n/2)
            return majorityElement;
        else 
            return -1;
    }
};