class Solution {
public:
    map<int,bool> findConnections(vector<vector<int>>& isConnected, map<int, bool> visited, int current) {
        visited[current] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[current][j] && visited[j] == false) {
                visited = findConnections(isConnected, visited, j);
            }
        }
        return visited;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0; 
        int size = isConnected.size();
        map<int, bool> visited;
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited = findConnections(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};