class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // count array algorithm 
        // build the frequency array, find max cost first 
        int max_cost = 0; 
        for (int cost: costs) {
            max_cost = max(cost, max_cost);
        }
        vector<int> counts(max_cost + 1, 0);
        int size = max_cost +1;
        // cout << "size of counts array is    " << size << endl; 
        // record the frequency of e ice cream cost in counts array 
        for (int i = 0; i < costs.size(); i++) {
            
            counts[costs[i]] += 1;
            // cout << "fill element " << costs[i] << "    to index " << counts[costs[i]] << endl;
        }
        int purchases = 0; 
        for (int cost = 0; cost < size; cost++) {
            if (coins <= 0) {
                break;
            }
            int freq = counts[cost];
            while (freq != 0) {
                if (coins < cost) {
                    break;
                }
                coins -= cost; 
                purchases++;
                freq--;
            }
        }
        return purchases; 
    }
};