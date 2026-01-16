class Solution {
public:
    struct worker {
        int cost;
        int idx;
        bool side;
    };
    struct compareCost {
        bool operator() (const worker a, worker b) {
            if (a.cost != b.cost) {
                return a.cost > b.cost;
            }
            return a.idx > b.idx;
        }
    };
    long long totalCost(vector<int>& costs, int k, int candidates) {
        std::priority_queue<worker, std::vector<worker>, compareCost> heap;
        int leftIdx;
        //get first candidates
        for (leftIdx = 0; leftIdx < candidates && leftIdx < costs.size(); leftIdx++) {
            heap.push({costs[leftIdx], leftIdx, false});
        }
        leftIdx--;
        //get last candidates if available
        int rightIdx = max(leftIdx + 1, (int) costs.size() - candidates);
        for (int i = rightIdx; i < costs.size(); i++) {
            heap.push({costs[i], i, true});
        }
        //pop k cheapest 
        long cost = 0;
        for (int i = 0; i < k; i++) {
            worker elem = heap.top();
            cost += elem.cost;
            heap.pop();
            //cout << "<" << elem.first << "," << elem.second << ">" << endl;
            bool moreToAdd = leftIdx < rightIdx - 1;
            if (moreToAdd && !elem.side) {
                leftIdx++;
                heap.push({costs[leftIdx], leftIdx, false});
            }
            else if (moreToAdd && elem.side) {
                rightIdx--;
                heap.push({costs[rightIdx], rightIdx, true});
            }
        }
        return cost;
    }
};