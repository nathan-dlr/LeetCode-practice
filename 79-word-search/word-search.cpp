class Solution {
public:
    bool wordExists(vector<vector<char>>& board, int currX, int currY, int currIdx, string word) {
        int m = board.size();
        int n = board[0].size();

        char temp = board[currX][currY];
        board[currX][currY] = '#';

        if (currIdx == word.size()) {
            return true;
        }
        if ((currX > 0) && (board[currX-1][currY] == word[currIdx])) {
            if (wordExists(board, currX - 1, currY, currIdx + 1, word)) {
                return true;
            }
        }
        if ((currX < m - 1) && (board[currX+1][currY] == word[currIdx])) {
            if (wordExists(board, currX + 1, currY, currIdx + 1, word)) {
                return true;
            }
        }
        if ((currY > 0) && (board[currX][currY-1] == word[currIdx])) {
            if (wordExists(board, currX, currY - 1, currIdx + 1, word)) {
                return true;
            }
        }
        if ((currY < n - 1) && (board[currX][currY+1] == word[currIdx])) {
            if (wordExists(board, currX, currY + 1, currIdx + 1, word)) {
                return true;
            }
        }
        board[currX][currY] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    bool exists = wordExists(board, i, j, 1, word);
                    if (exists) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};