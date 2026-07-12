class Solution {
public:
    int getSum(int a, int b) {
        int carryBit = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int currDigit = 0x01 << i;
            bool aHigh = a & currDigit;
            bool bHigh = b & currDigit;
            if (!carryBit && aHigh && bHigh || carryBit && (aHigh ^ bHigh)) {
                carryBit = 1;
            }
            else if ((!carryBit && (aHigh ^ bHigh)) || (carryBit && !aHigh && !bHigh)) {
                res |= currDigit;
                carryBit = 0;
            }
            else if (carryBit && aHigh && bHigh) {
                res |= currDigit;
                carryBit = 1;
            }
        }
        return res;
    }
};