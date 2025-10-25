class Solution {
public:
    int totalMoney(int n) {
        int lastMonday = 1;
        int yesterday = 1;
        int result = 1;
        for (int i = 1; i < n; i++) {
            if (!(i % 7)) {
                result += ++lastMonday;
                yesterday = lastMonday;
            }
            else {
                result += ++yesterday;
            }
        }
        return result;
    }
};