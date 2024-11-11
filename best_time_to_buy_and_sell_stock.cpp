// 121. Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIndex = 0;
        int sellIndex = 0;

        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < prices[buyIndex]) {
                buyIndex = i;
                sellIndex = i;
            }

            if(prices[i] > prices[sellIndex]) {
                sellIndex = i;
            }

            maxProfit = max(maxProfit, prices[sellIndex] - prices[buyIndex]);
        }

        return maxProfit;
    }
};
