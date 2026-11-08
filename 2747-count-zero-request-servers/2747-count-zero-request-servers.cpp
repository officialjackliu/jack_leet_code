class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_size = queries.size();
        vector<int> ans(q_size);

        // 1. Pair queries with their original indices and sort by time
        vector<vector<int>> q(q_size, vector<int>(2));
        for (int i = 0; i < q_size; i++) {
            q[i][0] = queries[i];
            q[i][1] = i;
        }
        sort(q.begin(), q.end());

        // 2. Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>&b) {
            return a[1] < b[1];
        });

        int l = 0, r = 0; 
        int active_servers = 0;
        vector<int> server_count(n + 1, 0);

        // 3. Process each query using sliding window pointers over logs 
        for (int i = 0; i < q_size; i++) {
            int time_limit = q[i][0];
            int start = time_limit - x;
            int end = time_limit;
            int original_idx = q[i][1]; 

            // Add logs that fall within or before 'end'
            while (r < logs.size() && logs[r][1] <= end) {
                int s_id = logs[r][0];
                if (server_count[s_id] == 0) {
                    active_servers++;
                }
                server_count[s_id]++;
                r++;
            }
            
            // Remove logs that fall before 'start' (outside the window)
            while (l < r && logs[l][1] < start) {
                int s_id = logs[l][0];
                server_count[s_id]--;
                if (server_count[s_id] == 0) {
                    active_servers--;
                }
                l++;
            }
            
            ans[original_idx] = n - active_servers;
        }

        return ans;
    }
};