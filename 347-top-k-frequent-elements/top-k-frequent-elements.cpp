class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minHeap;
        std::unordered_map<int, int> freq;
        std::vector<int> result;

        for (int num : nums) {
            freq[num]++;
        }

        for (const auto& [num, freq] : freq) {
            minHeap.push({freq, num});
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};