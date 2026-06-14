#include <limits>
#include <vector>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int min_val = numeric_limits<int>::max(), max_profix = 0;
        for (int price : prices) {
            min_val = min(min_val, price);
            max_profix = max(max_profix, price - min_val);
        }
        return max_profix;
    }
};