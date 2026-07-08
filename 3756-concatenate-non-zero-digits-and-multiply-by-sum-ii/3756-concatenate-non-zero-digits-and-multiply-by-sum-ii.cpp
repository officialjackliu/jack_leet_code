class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        /*
            steps to do: iterate through the queires, find left end and right
           end points on 's' do the sum calculation like 3754, store the mod
           number
        */
        long long MOD = 1e9 + 7;
        int n = s.length();

        // 1. Initialize the arrays (size n + 1 for 1-based indexing)
        vector<long long> prefix_sum(n + 1, 0);
        vector<int> prefix_count(n + 1, 0);
        vector<long long> prefix_x(n + 1, 0);
        vector<long long> pow10(n + 1, 1); // 10^0 is 1

        // 2. Precompute Powers of 10
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // 3. Build the Three Prefix Arrays in a single sweep
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0) {
                // If it's a non-zero digit, update all three!
                prefix_sum[i + 1] = prefix_sum[i] + digit;
                prefix_count[i + 1] = prefix_count[i] + 1;

                // Shift the previous x by 1 place (multiply by 10), add the new
                // digit, and modulo
                prefix_x[i + 1] = (prefix_x[i] * 10 + digit) % MOD;
            } else {
                // If it's a zero, we IGNORE it completely. Just carry over the
                // previous values.
                prefix_sum[i + 1] = prefix_sum[i];
                prefix_count[i + 1] = prefix_count[i];
                prefix_x[i + 1] = prefix_x[i];
            }
        }
        vector<int> queue_nums;

        for (vector<int>& query : queries) {
            int l = query[0];
            int r = query[1];

            // 1. Calculate the sum in O(1)
            long long current_sum = prefix_sum[r + 1] - prefix_sum[l];

            // 2. Find out how many non-zero digits are in this specific query
            // range
            int count = prefix_count[r + 1] - prefix_count[l];

            // 3. Extract x in O(1)
            // Formula: x = prefix_x_Right - (prefix_x_Left * 10^count)
            long long left_part = (prefix_x[l] * pow10[count]) % MOD;
            long long x = (prefix_x[r + 1] - left_part) % MOD;

            // C++ Modulo Trap: Subtraction can make 'x' negative!
            // We must fix it by adding MOD and taking modulo again.
            x = (x + MOD) % MOD;

            // 4. Calculate the final answer for this query
            long long ans = (x * current_sum) % MOD;
            queue_nums.push_back(ans);
        }

        return queue_nums;
    }
};