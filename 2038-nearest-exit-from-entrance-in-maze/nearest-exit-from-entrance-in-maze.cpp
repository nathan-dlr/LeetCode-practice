class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> positions;
        vector<int> curr;
        positions.push(entrance);
        unordered_map<int, set<int>> visited;
        int dist = 0;
        int size;
        
        while (!positions.empty()) {
            size = positions.size();
            for (int i = 0; i < size; i++) {
                curr = positions.front();
                positions.pop();
                bool atStart = (entrance[0] == curr[0]) && (entrance[1] == curr[1]);
                bool onEdge = curr[0] == 0 || curr[0] == maze.size() - 1 || curr[1] == 0 || curr[1] == maze[0].size() - 1;
                if (!atStart && onEdge) {
                    return dist;
                }
                if ((curr[0] > 0 && maze.size() > 1) && (maze[curr[0] - 1][curr[1]] == '.') && (!visited[curr[0] - 1].contains(curr[1]))) {
                    curr[0] -= 1;
                    positions.push(curr);
                    visited[curr[0]].insert(curr[1]);
                    curr[0] += 1;
                }
                if ((curr[0] < maze.size() - 1 && maze.size() > 1) && (maze[curr[0] + 1][curr[1]] == '.') && (!visited[curr[0] + 1].contains(curr[1]))) {
                    curr[0] += 1;
                    positions.push(curr);
                    visited[curr[0]].insert(curr[1]);
                    curr[0] -= 1;
                }
                if ((curr[1] > 0 && maze[0].size() > 1) && (maze[curr[0]][curr[1] - 1] == '.') && (!visited[curr[0]].contains(curr[1] - 1))) {
                    curr[1] -= 1;
                    positions.push(curr);
                    visited[curr[0]].insert(curr[1]);
                    curr[1] += 1;
                }
                if ((curr[1] < maze[0].size() - 1 && maze[0].size() > 1) && (maze[curr[0]][curr[1] + 1] == '.') && (!visited[curr[0]].contains(curr[1]+1))) {
                    curr[1] += 1;
                    positions.push(curr);
                    visited[curr[0]].insert(curr[1]);
                    curr[1] -= 1;
                }
            }
            dist++;
        }
        return -1;
    }
};