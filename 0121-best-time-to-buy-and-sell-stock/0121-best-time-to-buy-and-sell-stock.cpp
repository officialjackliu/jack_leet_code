class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // kadane's algorithm
        if (prices.size() == 1) {
            return 0;
        }
        int result = 0; 
        int minStart = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // Either extend the previous subarray or start 
            // new from current element
            minStart = min(prices[i], minStart);
            // Update result if the new subarray sum is larger
            result = max(result, prices[i] - minStart);
        }
        return result; 
    }
};