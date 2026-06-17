class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end()); 
        if (citations[0] >= citations.size()) {
            return citations.size();
        }
        int h = 0; 
        // int n = 
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (citations[i] > h && citations[i] != 0) {
                h++;
            }
        }
        return h;
    }
};