class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<>> larger;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(larger.empty() || num <= smaller.top()) smaller.push(num);
        else larger.push(num);

        if(smaller.size() > 1 + larger.size()){
            larger.push(smaller.top());
            smaller.pop();
        }
        else if(larger.size() > 1 + smaller.size()){
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if((smaller.size() + larger.size()) % 2 == 0){
            return (smaller.top() + larger.top()) / 2.0;
        }
        else if(smaller.size() > larger.size()) return smaller.top();
        else return larger.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */