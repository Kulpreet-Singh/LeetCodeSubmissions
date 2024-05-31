class Solution {
public:
    string largestOddNumber(string num) {
        int i=0;
        int j=num.size()-1;
        while(j>=0){
            if((num[j]-'0')%2==1){
                break;
            }
            j--;
        }
        return num.substr(i, j+1);
    }
};