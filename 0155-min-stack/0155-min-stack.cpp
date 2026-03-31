class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;  
    }
    
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
               
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long el = st.top();
        st.pop();

        if (el < mini) {
            
            mini = 2LL * mini - el;
        }
    }
    
    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        if (el < mini)
            return (int)mini; 
        else
            return (int)el;
    }
    
    int getMin() {
        return (int)mini;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */