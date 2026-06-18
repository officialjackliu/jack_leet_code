class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        
        int current_gas = 0;
        int start_index = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            // Track the overall totals to see if a solution is possible
            total_gas += gas[i];
            total_cost += cost[i];
            
            // Track our current tank for this specific journey
            current_gas += gas[i] - cost[i];
            
            // If our tank drops below zero, this starting point (and any station before 'i') failed!
            if (current_gas < 0) {
                start_index = i + 1; // Try the very next station
                current_gas = 0;     // Reset tank for the new journey
            }
        }
        
        // If we don't have enough gas overall, return -1. Otherwise, return our found start!
        if (total_gas < total_cost) {
            return -1;
        }
        
        return start_index;
    }
};