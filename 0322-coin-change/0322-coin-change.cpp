class Solution {
public:
    // redo count from bottom to up, memoize
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return amount;
        }
        vector<int> coin_changes(amount + 1, INT_MAX-1);
        // 0 at index 0 means there are totally 0 ways of coin exchange to reach 0 dollars amount 
        coin_changes[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int coin: coins) {
                if (coin != INT_MAX && coin_changes[i] != INT_MAX-1 && i + coin <= amount) {
                    // take the coin, or do nothing 
                    coin_changes[i + coin] = min(coin_changes[i + coin], 1 + coin_changes[i]);
                }
            }
        }
        return (coin_changes[coin_changes.size() - 1] == INT_MAX - 1) ? -1 : coin_changes[coin_changes.size() - 1]; 
    }
};