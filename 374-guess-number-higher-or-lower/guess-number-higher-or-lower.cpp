/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int floor = 0;
        int ceiling = n;
        int num = n / 2;
        int result = guess(num);
        while (result) {
            if (result < 0) {
                ceiling = num - 1;
                num = floor + (ceiling - floor) / 2;
            }
            else {
                floor = num + 1;
                num = floor + (ceiling - floor) / 2;
            }
            result = guess(num);
        }
        return num;
    }
};