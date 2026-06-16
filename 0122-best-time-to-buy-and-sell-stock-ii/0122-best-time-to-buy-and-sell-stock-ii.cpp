class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // like 714 two 1-D vectors to track costs and profits
        vector<int> buy(prices.size());
        vector<int> sell(prices.size());
        // initialize buy and sell rate
        buy[0] = prices[0];
        sell[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // buy options: do nothing (holds the previous bought option) or buy
            // a new stock
            buy[i] = min(buy[i - 1], prices[i] - sell[i - 1]);
            // sell options, holds the stock, or sell a stock
            sell[i] = max(sell[i - 1], prices[i] - buy[i - 1]);
            cout << "at index   " << i << "     buy: " << buy[i]
                 << "   sell: " << sell[i] << endl;
        }
        return sell[prices.size() - 1];
    }
};