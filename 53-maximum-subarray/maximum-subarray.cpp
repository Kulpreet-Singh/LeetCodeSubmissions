class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum =0;
        for(auto num: nums){
            sum+=num;
            if(maxSum<sum) maxSum=sum;
            if(sum<0) sum=0;

        }
        return maxSum;
    }
};