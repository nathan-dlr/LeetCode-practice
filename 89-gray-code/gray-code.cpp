class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0b00);
        res.push_back(0b01);

        int stop = 1 << (n-1);
        for (int i = 2; i <= stop; i = i << 1) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(res[j] + i);
            }
        }
        return res;
    }
};