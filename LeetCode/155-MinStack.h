#include<stack>
using std::stack;
using std::pair;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (stk.size() == 0) {
            stk.push({ x, x });
        }
        else {
            stk.push({ x, min(x, stk.top().second) });
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
private:
    stack<pair<int, int>> stk;
};

void test155() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin(); 
    minStack->pop();
    minStack->top();      
    minStack->getMin(); 

}
