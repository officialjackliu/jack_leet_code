class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int nums = 0; 
        for (int cost: costs) {
            coins -= cost; 
            if (coins >= 0) {
                nums++;
            } else {
                break;
            }
        }
        return nums;
    }
};