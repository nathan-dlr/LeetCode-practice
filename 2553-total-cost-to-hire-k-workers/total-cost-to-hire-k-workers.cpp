class Solution {
public:
    struct compareCost {
        bool operator() (const std::pair<int, int> a, std::pair<int, int> b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        }
    };
    long long totalCost(vector<int>& costs, int k, int candidates) {
        unordered_map<int, bool> idxToSide;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compareCost> heap;
        int leftIdx;
        //get first candidates
        for (leftIdx = 0; leftIdx < candidates && leftIdx < costs.size(); leftIdx++) {
            heap.push({costs[leftIdx], leftIdx});
            idxToSide[leftIdx] = false;
        }
        leftIdx--;
        //get last candidates if available
        int rightIdx = max(leftIdx + 1, (int) costs.size() - candidates);
        for (int i = rightIdx; i < costs.size(); i++) {
            heap.push({costs[i], i});
            idxToSide[i] = true;
        }
        //pop k cheapest 
        long cost = 0;
        for (int i = 0; i < k; i++) {
            std::pair<int, int> elem = heap.top();
            cost += elem.first;
            heap.pop(); 
            //cout << "<" << elem.first << "," << elem.second << ">" << endl;
            if ((leftIdx < rightIdx - 1) && !idxToSide[elem.second]) {
                leftIdx++;
                heap.push({costs[leftIdx], leftIdx});
                idxToSide[leftIdx] = false;
            }
            else if ((leftIdx < rightIdx - 1) && idxToSide[elem.second]) {
                rightIdx--;
                heap.push({costs[rightIdx], rightIdx});
                idxToSide[rightIdx] = true;
            }
        }
        return cost;
    }
};