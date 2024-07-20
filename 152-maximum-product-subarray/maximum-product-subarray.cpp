class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int maxProduct = INT_MIN;
        double currMinProduct = 1;
        double currMaxProduct = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                currMinProduct = 0;
                currMaxProduct = 0;
            } else if (nums[i] > 0) {
                currMaxProduct *= nums[i];
                currMinProduct = min((double)0, currMinProduct * nums[i]);
            } else {
                double temp = currMaxProduct;
                currMaxProduct = max((double)0, currMinProduct * nums[i]);
                currMinProduct = temp * nums[i];
            }
            if (maxProduct < currMaxProduct) {
                maxProduct = currMaxProduct;
            }
            if (currMaxProduct == 0)
                currMaxProduct = 1;
            if (currMinProduct == 0)
                currMinProduct = 1;
        }
        return maxProduct;
    }
};