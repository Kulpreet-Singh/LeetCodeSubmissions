class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int p=0, n=1;
        vector<int> result(nums.size(), 0);
        for(auto num: nums){
            if(num>0){
                result[p] = num;
                p+=2;
            } else {
                result[n] = num;
                n+=2;
            }
        }
        
        return result;
    }
};