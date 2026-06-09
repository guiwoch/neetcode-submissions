#include <stack>
class MinStack {
  public:
    void push(int val) {
        stack.push(val);
        if (min.empty() || min.top() >= val) {
            min.push(val);
        }
    }

    void pop() {
        if (!stack.empty()) {
            if (stack.top() == min.top()) {
                min.pop();
            }
            stack.pop();
        }
    }

    int top() { return stack.top(); }

    int getMin() { return min.top(); }

  private:
    std::stack<int> stack;

    // each element is the minimum from the idx onwards
    std::stack<int> min;
};