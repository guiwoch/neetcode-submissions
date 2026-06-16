#include <stack>
#include <string>
using namespace std;
class Solution {
  public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;

        stack<char> stack;
        for (const char c : s) {
            switch (c) {
            case '{':
            case '(':
            case '[':
                stack.push(c);
                break;
            case '}':
                if (!stack.empty() && stack.top() == '{')
                    stack.pop();
                else
                    return false;
                break;
            case ')':
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    return false;
                break;
            case ']':
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    return false;
                break;
            default:
                return false;
            }
        }
        if (stack.empty()){
            return true;
        }
        return false;
    }
};