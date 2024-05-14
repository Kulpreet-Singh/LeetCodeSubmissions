class Solution {
public:

// 000 - 0
// 001 - 1
// 010 - 3
// 011 - 0
// 100 - 4
// 101 - 1
// 110 - 7
// 111 - 0
// 1000 - 8

    int findXor1ToN(int n){
        switch(n%4){
            case 0: return n;
            case 1: return 1;
            case 2: return n+1;
            case 3: return 0;
            default: return -1;
        }
        return -1;
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedXor = findXor1ToN(n);
        int actualXor = 0;
        for(auto it: nums){
            actualXor = actualXor ^ it;
        }
        return expectedXor ^ actualXor;
    }
};

