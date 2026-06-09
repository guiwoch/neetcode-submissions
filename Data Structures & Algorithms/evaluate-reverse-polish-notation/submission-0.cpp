#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stack;
        for (const string str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                switch (str[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
                }
            } else {
                stack.push(stoi(str));
            }
        }
        return stack.top();
    }
};