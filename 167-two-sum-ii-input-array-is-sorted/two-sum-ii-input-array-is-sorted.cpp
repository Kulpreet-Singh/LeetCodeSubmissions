class Solution {
public:
    // two pointer approach
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int right = n-1;
        int left = 0;
        while(left < right){
            long sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1, right+1};
            } else if (sum<target){
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};