class Solution {
public:
    bool canEatInKHours(vector<int>& piles, int k, int h) {
        for (int pile : piles) {
            int hours = pile / k;
            h -= (hours == 0) ? 1 : hours;
            if (hours && pile % k) {
                h--;
            }
            if (h < 0) {
                return false;
            }
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search between 0 and h to find the minimum hours possible to eat all the bananas
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int mid = high / 2;
        int min = h;

        while (low <= high) {
            bool canEat = canEatInKHours(piles, mid, h);
            if (canEat) {
                min = mid;
                high = mid - 1;
            }
            if (!canEat) {
                low = mid + 1;
            }
            mid = (high + low) / 2;
        }
        return min;
    }
};