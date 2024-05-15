class Solution {
public:
// optimal approach - Boyer-Moore Majority Voting Algorithm
// there can't be more than 2 elements which are greater than n/3 elements
// hence we can simply maintain the exceeding counts for the majority elements
// increase exceeding counts if same element found again
// decrease exceeding counts if element diff than both the candidates is found
// reset the majority elements in case the exceeding count equals 0

// This works as even if the majority elements has been tied till some index, it will still prevail in the rest of the array if it has to be greater than n/3 elements.

// Time - O(n), Space - O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int exceedingCount1 = 0, exceedingCount2 = 0;
        int majorityElement1 = 0, majorityElement2 = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if (nums[i] == majorityElement1) {
                exceedingCount1++;
            } else if (nums[i] == majorityElement2) {
                exceedingCount2++;
            } else if (exceedingCount1 == 0) {
                majorityElement1 = nums[i];
                exceedingCount1++;
            } else if (exceedingCount2 == 0) {
                majorityElement2 = nums[i];
                exceedingCount2++;
            } else {
                exceedingCount1--;
                exceedingCount2--;
            }
        }
        // still have to check if these elements are greater than n/3 elements, as these are only exceeding elements, not necessarily imply that these are greater than n/3 elements
        int cnt1 = 0, cnt2 = 0;
        for(auto it: nums){
            if(it == majorityElement1) cnt1++;
            else if(it == majorityElement2) cnt2++;
        }
        vector<int> result;
        if(cnt1>n/3) result.push_back(majorityElement1);
        if(cnt2>n/3) result.push_back(majorityElement2);
        return result;
    }
};