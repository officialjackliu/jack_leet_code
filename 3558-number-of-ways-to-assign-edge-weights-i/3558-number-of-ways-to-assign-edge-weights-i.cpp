class Solution {
    // 1. DFS helper function, track current_node and its predecesssor (parent_node)
    int dfs(int current_node, int parent_node, unordered_map<int, vector<int>>& adj) {
        int max_child_depth = 0; 

        // Visit all connected neighbors 
        for (int neighbor : adj[current_node]) {
            // prevent infinte loops by NOT going back to the parent
            if (neighbor != parent_node) {
                // recursively find the depth of this neighbor's path
                int depth = dfs(neighbor, current_node, adj);
                // add 1 to account for the edge connecting us to the neighbor
                max_child_depth = max(max_child_depth, 1 + depth);
            }
        }

       // Returns the maximum number of edges from this node to the deepest leaf
       return max_child_depth;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // 2. build the adjacency list 
        unordered_map<int, vector<int>> adj; 
        for (const auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            // undirected graph: add both directions 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 3. start dfs from the root
        int max_depth = dfs(1,-1, adj); 

        // 4. compute depth 
        if (max_depth == 0) {
            return 0; 
        }
        long long ways = 1;
        int mod = (pow(10, 9) + 7);
        // multiply by 2 and immediately modulo at each step 
        for (int i = 0; i < max_depth -1; i++) {
            ways = (ways * 2) % mod; 
        }
        return ways;
     }
};