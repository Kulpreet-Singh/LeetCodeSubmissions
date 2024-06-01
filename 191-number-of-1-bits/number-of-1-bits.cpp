class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        for(int i=0;i<31; i++){
            int powOf2 = 1<<i;
            if((n & powOf2) == powOf2){
                count++;
            } 
        }
        return count;
    }
};