class MinStack {
public:

    stack<int> st;
    priority_queue<int,vector<int>,greater<int>> pq;

    MinStack() {
        
    }
    
    void push(int value) {
        pq.push(value);
        st.push(value);
    }
    
    void pop() {
        if(st.empty()) return ;
        int x=st.top();
        vector<int> temp;
        while(x!=pq.top()){
            temp.push_back(pq.top());
            pq.pop();
        }
        pq.pop();
        int n=temp.size();

        for(int i=0;i<n;i++) pq.push(temp[i]);
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */