class SmallestInfiniteSet {
public:
    set<int> sis;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            sis.insert(i);
        }
    }
    
    int popSmallest() {
        if (!sis.empty()) {
            int smallest = *sis.begin();
            sis.erase(sis.begin());
            return smallest;
        }
        else {
            return 0;
        }
    }
    
    void addBack(int num) {
        sis.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */