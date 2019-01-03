class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //  Store unique nodes according to edge to other node (neighbours)
        vector<unordered_set<int>> adj(n);
        for (pair<int, int> p : edges) {
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }
        //  Initialize result vector
        vector<int> current;
        //  Base cases: 0 nodes and 1 node
        if (n == 1) {
            current.push_back(0);
            return current;
        }
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i].size() == 1) {
                current.push_back(i);
            }
        }
        //  BFS
        while (true) {
            vector<int> next;
            for (int node : current) {
                for (int neighbor : adj[node]) {
                    adj[neighbor].erase(node);
                    if (adj[neighbor].size() == 1) next.push_back(neighbor);
                }
            }
            if (next.empty()) return current;
            current = next;
        }
    }
};