class Solution {
public:
    static int leftOf(const vector<int>& vec, int index) {
        return index <= 0 ? std::numeric_limits<int>::min() : vec[index - 1];
    }
    static int rightOf(const vector<int>& vec, int index) {
        return index >= vec.size() ? std::numeric_limits<int>::max() : vec[index];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int half = size / 2;
        vector<int>& smallVec = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& largeVec = nums1.size() < nums2.size() ? nums2 : nums1;
    
        int l = 0;
        int r = smallVec.size();
        int partition1 = 0;
        int partition2 = 0; 
        while (l <= r) {
            int mid = (l + r) / 2;
            partition1 = mid;
            partition2 = half - mid;
            
            bool inBounds1 = leftOf(smallVec, partition1) <= rightOf(largeVec, partition2);
            bool inBounds2 = leftOf(largeVec, partition2) <= rightOf(smallVec, partition1);
            if (inBounds1 && inBounds2) {
                break;
            }
            else if (!inBounds1) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (size % 2) {
            return std::min(rightOf(smallVec, partition1), rightOf(largeVec, partition2));
        }
        else {
            int maxLeft  = std::max(leftOf(smallVec, partition1),  leftOf(largeVec, partition2));
            int minRight = std::min(rightOf(smallVec, partition1), rightOf(largeVec, partition2));
            return (maxLeft + minRight) / 2.0;
        }
    }
};