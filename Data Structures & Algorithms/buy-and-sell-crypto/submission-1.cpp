#include <limits>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int min_val = numeric_limits<int>::max(), max_profit = 0;
        for (int price : prices) {
            min_val = min(min_val, price);
            max_profit = max(max_profit, price - min_val);
        }
        return max_profit;
    }
};