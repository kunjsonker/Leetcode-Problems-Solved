class MinStack {
public:
    stack<long long> st;
    long long minn;

    MinStack() {}

    void push(int value) {

        if(st.empty()) {
            minn = value;
            st.push(value);
        }
        else if (value >= minn) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minn);
            minn = value;
        }
    }

    void pop() {
        if (st.top() < minn) {
            minn = 2 * minn - st.top();
            st.pop();
        } else {
            st.pop();
        }
    }

    int top() { 
        if (st.top() >= minn)
        return st.top();
        else
        return minn;
    }

    int getMin() { return minn; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */