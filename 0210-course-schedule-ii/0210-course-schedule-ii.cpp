class Solution {
public:
    // use boolean to identify can not convert cases
    bool dfs(int index, vector<int>& states, vector<vector<int>>& adj,
             stack<int>& st) {
        states[index] = 1;

        for (int descents : adj[index]) {
            if (states[descents] == 1) {
                return true;
            } 
            if (states[descents] == 0) {
                if (dfs(descents, states, adj, st) == true) {
                    return true;
                }
            }
        }
        st.push(index);
        states[index] = 2;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // implement a topological sort using DFS, code is borrowed from
        // GeekForGeek similar code and algorithm as 209 Course Schedule I, add
        // a global stack to filter the dependency order for graph, the last
        // push node is the first one we should traverse as it has the least
        // dependency

        vector<int> orders;
        // initialize an adjacency matrix & visited
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        stack<int> st;
        // 1. build adj graph
        for (vector<int> edge : prerequisites) {
            int source = edge[1];
            int destination = edge[0];
            adj[source].push_back(destination);
        }

        // 2. run dfs
        for (int i = 0; i < numCourses; i++) {
            if (states[i] == 0) {
                if (dfs(i, states, adj, st) == true) {
                    return {};
                }
            }
        }
        // 3. construct traversal path
        while (st.empty() == false) {
            orders.push_back(st.top());
            st.pop();
        }
        return orders;
    }
};