class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        map<int, int> mp2;
        vector<int> vec1;
        vector<int> vec2;
        vector<vector<int>> diff;
        for (int nums : nums1) {
            mp1[nums]++;
        }
        for (int nums : nums2) {
            mp2[nums]++;
        }
        for (int nums : nums2) {
            if (mp1.find(nums) == mp1.end() && mp2[nums] != 0) {
                vec2.push_back(nums);
                mp2[nums] = 0;
            }
        }
        for (int nums : nums1) {
            if (mp2.find(nums) == mp2.end() && mp1[nums] != 0) {
                    vec1.push_back(nums);
                    mp1[nums] = 0;                    
            }
        }
        diff.push_back(vec1);
        diff.push_back(vec2);
        return diff;
    }
};