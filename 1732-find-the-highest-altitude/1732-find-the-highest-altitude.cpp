class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0; 
        // vector<int> altitude; 
        // altitude.push_back(0);
        int current_height = 0;
        for (int i = 0; i < gain.size(); i++) {
            current_height += gain[i];
            max_height = (max_height > current_height) ? max_height : current_height;
        }
        return max_height;
    }
};