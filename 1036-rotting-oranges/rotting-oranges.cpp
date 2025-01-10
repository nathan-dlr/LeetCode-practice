class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0;
        queue<array<int,2>> visit; 
        array<int,2> node;
        int row_size = grid.size();
        int col_size = grid[0].size();
        int size;
        int row;
        int col;
        
        for (row = 0; row < row_size; row++) {
            for (col = 0; col < col_size; col++) {
                if (grid[row][col] == 2) {
                    visit.push({row,col});
                }
            }
        }

        int first = 1;
        while (!visit.empty()) {
            size = visit.size();
            for (int i = 0; i < size; i++) {
                node = visit.front();
                row = node[0];
                col = node[1];
                visit.pop();

                if (row != 0 && grid[row-1][col] == 1) {
                    visit.push({row-1,col});
                    grid[row-1][col] = 2;
                }
                if (row != row_size - 1 && grid[row+1][col] == 1) {
                    visit.push({row+1,col});
                    grid[row+1][col] = 2;
                }
                if (col != 0 && grid[row][col-1] == 1) {
                    visit.push({row,col-1});
                    grid[row][col-1] = 2;
                }
                if (col != col_size - 1 && grid[row][col+1] == 1) {
                    visit.push({row,col+1});
                    grid[row][col+1] = 2;

                }
            }
            if (!first) {
                min++;
            }
            else { 
                first = 0;
            }
        }
        for (row = 0; row < row_size; row++) {
            for (col = 0; col < col_size; col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }
        return min;
    }
};