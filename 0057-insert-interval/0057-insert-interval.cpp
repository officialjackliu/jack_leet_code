class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        // base case
        if (intervals.empty() == true) {
            return {newInterval};
        }
        // intervals is stored in NON-OVERLAPPING SORTED ascending order, a
        // newInterval is placed and merge / connect interval and is overlaps
        // with, int insert_start = newInterval[0], insert_end = newInterval[1];
        int curr_start = 0, curr_end = 0;
        int merged_start = newInterval[0], merged_end = newInterval[1];
        bool push_merged = false;
        vector<vector<int>> inserted_intervals;
        for (vector<int> pair : intervals) {
            curr_start = pair[0];
            curr_end = pair[1];
            // 1. front the interval does not overlap with newInterval, insert
            // it as an individual pair
            if (curr_end < merged_start) {
                inserted_intervals.push_back({curr_start, curr_end});
            }
            // 2 interval does not overlap with the merged interval
            else if (curr_start > merged_end) {
                if (push_merged == false) {
                    inserted_intervals.push_back({merged_start, merged_end});
                    push_merged = true;
                }
                inserted_intervals.push_back({curr_start, curr_end});
            }
            // 3. the interval does overlap with newInterval,merge them together
            // a. the front, interval is in thef front of newInterval such it
            // overlaps witht he head of the interval b. near the end of the
            // interval, such that it's end or start is closer to the end
            else if (curr_end >= merged_start || curr_start >= merged_start ||
                     curr_end <= merged_end || curr_start <= merged_end) {
                merged_start = min(curr_start, merged_start);
                merged_end = max(curr_end, merged_end);
            }
        }
        if (push_merged == false) {
            inserted_intervals.push_back({merged_start, merged_end});
            push_merged = true;
        }
        return inserted_intervals;
    }
};