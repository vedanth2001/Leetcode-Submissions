class BrowserHistory {
public:

    stack<string> fwd;
    stack<string> bwd;
    BrowserHistory(string homepage) {
        bwd.push(homepage);
    }
    
    void visit(string url) {
        bwd.push(url);
        while(!fwd.empty()){
            fwd.pop();
        } 
    }
    
    string back(int steps) {
        while(steps!=0 && bwd.size() > 1){
            steps--;
            fwd.push(bwd.top());
            bwd.pop();
        }
        return bwd.top();
    }
    
    string forward(int steps) {
        while(steps!=0 && !fwd.empty()){
            steps--;
            bwd.push(fwd.top());
            fwd.pop();
        }
        if (fwd.empty()) {
            return bwd.top(); 
        }
        return bwd.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */