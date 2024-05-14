class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 =0, cnt1 = 0, cnt2 = 0;
        for(auto it: nums){
            if(it ==0) cnt0++;
            else if (it ==1) cnt1++;
            else if (it ==2) cnt2++;
        }
        int ind = 0;
        for ( int i=0;i<cnt0; i++){
            nums[ind+i] = 0;
        }
        ind = cnt0;
        for ( int i=0;i<cnt1; i++){
            nums[ind+i] = 1;
        }
        ind = cnt0+cnt1;
        for ( int i=0;i<cnt2; i++){
            nums[ind+i] = 2;
        }
    }
};