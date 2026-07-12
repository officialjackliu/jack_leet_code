class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        /*


        */


        vector<int> copy = arr; 
        sort(copy.begin(), copy.end());
        map<int, int> rank_map; 
        int rank = 1;
        for (int i = 0; i < copy.size(); i++) {
            if (rank_map.count(copy[i]) == 1) {
                continue;
            }
            rank_map[copy[i]] = rank;
            rank++;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank_map[arr[i]];
        }
        return arr;
    }
};