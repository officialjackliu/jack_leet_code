class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
/*

    merge condition: overlap: last index > first, we can just merge them 
    // for (int row = 0; row < intervals.size(); row++) {
    //     for (int col = 0; col < intervals[row].size(); col++) {
    //         cout << "sorted intervals is " << intervals[row][col] << "      ";
    //     }
    //     cout << endl;
    // }
*/
    
    sort(intervals.begin(), intervals.end()); 
    int furthest_end = intervals[0][1], curr_start = 0, curr_end = 0;
    // merge_end also present the previous end 
    int merge_start = intervals[0][0];
    vector<vector<int>> merged_intervals; 
    for (int i = 1; i < intervals.size(); i++) {
        curr_start = intervals[i][0];
        curr_end = intervals[i][1]; 
        // compare curr_start with previous end, 1. if out of bound, insert a intervals pair, 2. otherwise "merge with the current pair, check if it extends the end "
        if (curr_start > furthest_end) {
            merged_intervals.push_back({merge_start, furthest_end}); 
            merge_start = curr_start; 
            furthest_end = max(furthest_end, curr_end); 
        }
        else {
            furthest_end = max(furthest_end, curr_end); 
        }
    }
    
    // check if we need to make one more insert
    merged_intervals.push_back({merge_start, furthest_end});
    return merged_intervals;
    }   
};