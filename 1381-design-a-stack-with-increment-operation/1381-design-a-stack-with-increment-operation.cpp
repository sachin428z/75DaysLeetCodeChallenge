class CustomStack {
public:
    vector<int> stackVector;
    int topIndex;

    CustomStack(int maxSize) {
        stackVector.resize(maxSize);
        topIndex=-1;
    }
    
    void push(int x) {
        if(topIndex<(int)(stackVector.size())-1) {
            stackVector[++topIndex]=x;
        }
    }
    
    int pop() {
        if(topIndex>=0) {
            return stackVector[topIndex--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int limit=min(k,topIndex+1);
        for(int i=0;i<limit;i++) {
            stackVector[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */