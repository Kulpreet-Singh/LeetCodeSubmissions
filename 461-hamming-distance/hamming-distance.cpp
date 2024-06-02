class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 1 << i;
            if (((x & mask) == mask && (y & mask) == 0) ||
                ((x & mask) == 0 && (y & mask) == mask)) {
                count++;
            }
        }
        return count;
    }
};