class Solution {
public:
    int height;
    int width;
    int getIslandArea(vector<vector<int>>& grid, int startX, int startY) {
        int area = 0;
        std::queue<std::pair<int,int>> bfs;
        bfs.push({startX, startY});
        while (!bfs.empty()) {
            area++;
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            if (x != 0 && grid[y][x-1] == 1) {
                grid[y][x-1] = -1;
                bfs.push({x-1, y});
            }
            if (x != width - 1 && grid[y][x+1] == 1) {
                grid[y][x+1] = -1;
                bfs.push({x+1, y});
            }
            if (y != 0 && grid[y-1][x] == 1) {
                grid[y-1][x] = -1;
                bfs.push({x, y-1});
            }
            if (y != height -1 && grid[y+1][x] == 1) {
                grid[y+1][x] = -1;
                bfs.push({x, y+1});
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        int maxArea = 0;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == 1) {
                    grid[y][x] = -1;
                    maxArea = std::max(maxArea, getIslandArea(grid, x, y));
                }
            }
        }
        return maxArea; 
    }
};