class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> lines;
        int matches = 0;

        for (int i = 0; i < grid.size(); i++) {
            lines[grid[i]]++;
        }
        vector<int> columns;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                columns.push_back(grid[j][i]);
            }
            if (lines.find(columns) != lines.end()) {
                matches += lines[columns];
            }
            columns.clear();
        }
        return matches;
    }
};