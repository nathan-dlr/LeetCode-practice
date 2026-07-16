class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](std::pair<double,int> l, std::pair<double,int> r) {
            return l.first < r.first;
        };
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double,int>>, decltype(cmp)> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double dist = std::sqrt((x * x) + (y * y));

            maxHeap.push({dist, i});
            if (maxHeap.size() > k) maxHeap.pop();
        }

        std::vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return res;
    }
};