class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        int powOf2 = 1;
        for(int i=0;i<31; i++){
            powOf2 = 1<<i;
            if((n & powOf2) == powOf2){
                count++;
            } 
            cout<<powOf2<<" ";
        }
        if(abs(n) > abs(powOf2)){
            return false;
        }

        if(count==1){
            return true;
        }
        return false;
    }
};