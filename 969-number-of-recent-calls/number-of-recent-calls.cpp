class RecentCounter {
private: 
    queue<int> elements;

public:
    RecentCounter() {   
    }
    
    int ping(int t) {
        int range = t - 3000;
        elements.push(t);
        while (elements.front() < range) {
            elements.pop();
        }
        return elements.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */