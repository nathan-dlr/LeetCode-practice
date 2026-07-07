class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = static_cast<uint32_t>(n);
        uint32_t topBit = 0x80000000;
        uint32_t bottomBit = 0x00000001;
        int shiftAmount = 31;

        while (shiftAmount > 0) {
            unsigned int temp = res & topBit;
            res &= ~topBit;
            res |= ((res & bottomBit) << shiftAmount);
            res &= ~bottomBit;
            res |= (temp >> shiftAmount);

            shiftAmount -= 2;
            topBit >>= 1;
            bottomBit <<= 1;

        }
        return static_cast<int>(res);
    }
};
