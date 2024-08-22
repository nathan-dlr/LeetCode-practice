class Solution {
public:
    unordered_map<int, vector<int>> adj, back;
    int min = 0;
    void dfs (int root, vector<bool>& visited) {
        visited[root] = true;
        for (int child : adj[root]) {
            if(!visited[child]) {
                min++;
                dfs(child, visited);
            }
        }
        for (int child : back[root]) {
            if (!visited[child]) {
                dfs(child, visited);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        for (auto edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            back[edge[1]].push_back(edge[0]);
        }
        dfs(0,visited);
        return min;
        
    }
};