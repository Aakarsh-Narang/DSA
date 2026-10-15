
class BrowserHistory {
public:
    list<string> history;
    list<string>::iterator ptr;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        ptr = history.begin();
    }

    void visit(string url) {
        // Delete all forward history
        auto it = next(ptr);
        history.erase(it, history.end());

        history.push_back(url);
        ptr = prev(history.end());
    }

    string back(int steps) {
        while (steps-- > 0 && ptr != history.begin()) {
            ptr--;
        }
        return *ptr;
    }

    string forward(int steps) {
        while (steps-- > 0 && next(ptr) != history.end()) {
            ptr++;
        }
        return *ptr;
    }
};


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */