/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start

#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        m_st = stack<int>();
        // m_st_min = stack<int>();
        min_val = __INT_MAX__;
    }
    
    void push(int x) {
        // m_st.push(x);
        // if (m_st_min.empty() || m_st_min.top() > x) {
        //     m_st_min.push(x);
        // } else {
        //     m_st_min.push(m_st_min.top());
        // }

        if (x <= min_val) {
            m_st.push(min_val);
            min_val = x;
        }
        m_st.push(x);
    }
    
    void pop() {
        // if (m_st.empty() || m_st_min.empty()) return;

        // m_st.pop();
        // m_st_min.pop();

        if (m_st.empty()) return;

        int t = m_st.top();
        m_st.pop();
        if (t == min_val) {
            min_val = m_st.top();
            m_st.pop();
        }
    }
    
    int top() {
        return m_st.top();
    }
    
    int getMin() {
        // return m_st_min.top();
        return min_val;
    }

private:
    stack<int> m_st;
    // stack<int> m_st_min;
    int min_val;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

