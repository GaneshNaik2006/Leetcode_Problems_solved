class MinStack {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        pq.push(value);
    }
    
    void pop() {
        int x=st.top();
        vector<int> temp;
        while(x!=pq.top()){
            temp.push_back(pq.top());
            pq.pop();
        }
        pq.pop();

        int n=temp.size();

        for(int i=0;i<n;i++){
            pq.push(temp[i]);
        }
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