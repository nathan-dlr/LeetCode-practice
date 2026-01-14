class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ret(n, vector<int>(m));
        vector<vector<int>> prefix(n, vector<int>(m));
        vector<vector<int>> suffix(n, vector<int>(m));

        long long product = 1;
        int mod = 12345;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = product;
                product *= grid[i][j];
                product %= mod;
            }
        }

        product = 1;
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                suffix[i][j] = product; 
                product *= grid[i][j];
                product %= mod;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                product = prefix[i][j] * suffix[i][j];
                ret[i][j] = product % mod;
            }
        }
        return ret;
    }
};