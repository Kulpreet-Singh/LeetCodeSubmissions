class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int num = x ^ y;
        while (num) {
            if (num & 1) {
                count++;
            }
            num = num >> 1;
        }
        return count;
    }
};