class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<>> larger;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smaller.empty() && larger.empty()){
            smaller.push(num);
        }
        else if(!larger.empty() && num > larger.top()) larger.push(num);
        else smaller.push(num);

        if(smaller.size() > 1 + larger.size()){
            larger.push(smaller.top());
            smaller.pop();
        }
        if(larger.size() > 1 + smaller.size()){
            smaller.push(larger.top());
            larger.pop();
        }

        cout << smaller.size() << " "<<larger.size()<<endl;
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