class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
   
    MedianFinder() {
    
    }
    
    void addNum(int num) {
    if (s.empty() || num <= s.top()) {
        s.push(num);
    } else {
        g.push(num);
    }

    if (s.size() > g.size() + 1) {
        int curr = s.top();
        s.pop();
        g.push(curr);
    } else if (g.size() > s.size()) {
        int curr = g.top();
        g.pop();
        s.push(curr);
    }
}

    
    double findMedian() {
         if (s.size() == g.size()) {
            return (s.top() + g.top()) / 2.0;
        } else {
           return s.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */