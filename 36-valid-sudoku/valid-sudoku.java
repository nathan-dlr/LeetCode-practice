class Solution {
    public boolean isValidSudoku(char[][] board) {
        short[] rows = new short[9];
        short[] cols = new short[9];
        short[] boxes = new short[9];
        for (byte row = 0; row < 9; row++) {
            for (byte col = 0; col < 9; col++) {
                char current = board[row][col];
                if (current == '.') {
                    continue;
                }
                int num = 0x01 << (current - 0x30);
                int box_index = ((row / 3) * 3) + (col / 3);
                if ((boxes[box_index] & num) != 0) {
                    return false;
                }
                else {
                   boxes[box_index] |= num; 
                }
                if ((rows[row] & num) != 0) {
    
                    return false;
                }
                else {
                    rows[row] |= num;
                }
                if ((cols[col] & num) != 0) {
                    return false;
                }
                else {
                    cols[col] |= num;
                }
            }
        }
        return true;
    }
}