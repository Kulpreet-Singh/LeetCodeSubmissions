class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal;
        int count =0;
        while(num){
            count+=num&1;
            num = num>>1;
        }
        return count;
    }
};