class Solution {
public:
    //t1 should go before t2 if t1 is smaller than t2
    static bool comp(tuple<int, int> t1, tuple<int, int> t2) {
        return get<1>(t1) > get<1>(t2);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<tuple<int, int>> sorted_arr;
        //make vector of tuples to keep one-to-one matching of indexes
        for (int i = 0; i < nums1.size(); i++) {
            sorted_arr.push_back(make_tuple(nums1[i], nums2[i]));
        }

        //sort based on descending order of nums2
        sort(sorted_arr.begin(), sorted_arr.end(), comp);
        
        long ret = 0;
        long sum = 0;
        priority_queue<int,vector<int>, greater<int>> min_heap;
        for (auto& t : sorted_arr) {
            min_heap.emplace(get<0>(t));
            sum += get<0>(t);
            if (min_heap.size() > k) {
                sum -= min_heap.top();
                min_heap.pop();
            }
            if (min_heap.size() == k) {
                ret = max(ret, sum * get<1>(t));
            }
        }
        return ret;
    }
};