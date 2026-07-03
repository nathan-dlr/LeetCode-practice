class Solution {
public:
    int height;
    int width;
    void bfsIsland(vector<vector<char>>& grid, int i, int j) {

        std::queue<std::pair<int,int>> positions;
        positions.push({i,j});
        while (!positions.empty()) {
            std::pair<int,int> pos = positions.front();
            positions.pop();
            int x = pos.first;
            int y = pos.second;
            if (x != 0 && grid[y][x-1] == '1') {
                grid[y][x-1] = '2';
                positions.push({x - 1, y});
            }
            if (x != width - 1 && grid[y][x+1] == '1') {
                grid[y][x+1] = '2';
                positions.push({x + 1, y});
            }
            if (y != 0 && grid[y-1][x] == '1') {
                grid[y-1][x]= '2';
                positions.push({x, y - 1});
            }
            if (y != height - 1 && grid[y+1][x] == '1') {
                grid[y+1][x] = '2';
                positions.push({x, y + 1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;
        height = grid.size();
        width = grid[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '2';
                    numIslands++;
                    bfsIsland(grid, j, i);
                }
            }
        } 
        return numIslands;
    }
};