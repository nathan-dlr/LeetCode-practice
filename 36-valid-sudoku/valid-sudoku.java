class Solution {
    public boolean valid_row(char[] row) {
        HashSet<Character> set = new HashSet();
        for (byte i = 0; i < 9; i++) {
            if (row[i] != '.' && !set.add(row[i])) {
                return false;
            }
        }
        return true;
    }
    public boolean valid_column(char[][] board, byte col) {
        HashSet<Character> set = new HashSet();
        for (byte i = 0; i < 9; i++) {
            if (board[i][col] != '.' && !set.add(board[i][col])) {
                return false;
            }
        }
        return true;
    }
    public boolean valid_box(char[][] board, byte box_row, byte box_col) {
        HashSet<Character> set = new HashSet();
        for (byte i = box_row; i < box_row + 3; i++) {
            for (byte j = box_col; j < box_col + 3; j++) {
                if (board[i][j] != '.' && !set.add(board[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        for (byte i = 0; i < 9; i++) {
            if (!valid_row(board[i])) {
                return false;
            }
        }
        for (byte i = 0; i < 9; i++) {
            if (!valid_column(board, i)) {
                return false;
            }
        }
        for (byte i = 0; i < 9; i += 3) {
            for (byte j = 0; j < 9; j += 3) {
                if (!valid_box(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
}