class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> arr_freq;
        map<int, int> occur_freq;
        for (int nums : arr) {
            arr_freq[nums]++;
        }
        for (auto& num: arr_freq) {
            occur_freq[num.second]++;
            if (occur_freq[num.second] > 1) {
                return false;
            }
        }
        return true;
    }
};