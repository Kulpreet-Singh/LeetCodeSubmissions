class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int maxProfit = 0;
        int profit = 0;
        for(auto &price: prices){
            if(price<minPrice) minPrice = price;
            profit = price - minPrice;
            if(profit>maxProfit) maxProfit = profit;
        }
        return maxProfit;
    }
};