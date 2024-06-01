class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int count = 0;
        for(int i=0;i<31; i++){
            int powOf2 = 1<<i;
            if((n & powOf2) == powOf2){
                count++;
            } 
        }
        if(count==1){
            return true;
        }
        return false;
    }
};