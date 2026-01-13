class Solution {
public:
    vector<double> find_area(vector<vector<int>>& squares, double y) {
        double below = 0;
        double above = 0;
        for (int i = 0; i < squares.size(); i++) {
            double squareY = squares[i][1];
            double len = squares[i][2];
            int upperY = squareY + len;
            if (upperY <= y) {
                below += len * len;
            }
            else if (squares[i][1] >= y) {
                above += len * len;
            }
            else {
                below += len * (y - squareY);
                above += len * (upperY - y);
            }
        }
        return {above,below};
    }
    double separateSquares(vector<vector<int>>& squares) {
        double error = 0.00001; 
        double min = 0;
        double max = 0;
        double current;
        double next;
        double best = -1;
        
        //get starting point for bfs
        for (int i = 0; i < squares.size(); i++) {
            int upperY = squares[i][1] + squares[i][2];
            if (upperY > max) {
                max = upperY;
            }
        }

        //find min point using bfs
        current = max / 2;
        for (int i = 0; i < 350; i++) {
            vector<double> areas = find_area(squares, current);
            double above = areas[0];
            double below = areas[1];
            double diff = abs(below - above);
            if (diff <= error && (best == -1 || current < best)) {
                best = current;
                next = (current - min) / 2;
                max = current;
            }
            //need to go up
            else if (below < above) {
                next = (max + current) / 2;
                min = current;
            }
            //need to go down
            else {
                next = (current + min) / 2;
                max = current;
            }
            current = next;
        }
        return best != -1 ? best : current;
    }
};