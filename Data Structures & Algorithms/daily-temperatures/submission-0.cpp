// daily temperatures
#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> stack;
        vector<int> solution(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() &&
                   temperatures[stack.top()] < temperatures[i]) {
                solution[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return solution;
    }
};
