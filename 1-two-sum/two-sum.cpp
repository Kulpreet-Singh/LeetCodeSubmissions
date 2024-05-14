class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        int n = nums.size();
        vector<int> result;
        hash[nums[0]] = 0;
        for(int i=1;i<n;i++){
            if(hash.find(target-nums[i])!=hash.end()){
                result.push_back(hash[target-nums[i]]);
                result.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};