class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int maxProfit = 0;
        for(auto price: prices){
            minPrice = min(minPrice, price);
            maxProfit = max(price - minPrice, maxProfit);
        }
        return maxProfit;
    }
};