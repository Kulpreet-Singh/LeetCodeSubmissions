class Solution {
public:
    int getSum(int a, int b) {
        bool carryBit = 0;
        int sum = 0;
        for(int i=0;i<32;i++){
            bool aBit = (a&(1<<i));
            bool bBit = (b&(1<<i));
            bool sumBit = (aBit ^ bBit) ^ carryBit;
            carryBit = (aBit & bBit) | ((aBit|bBit)&carryBit);
            sum = sum|(sumBit<<i);
        }
        return sum;

    }
};