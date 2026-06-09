#include <vector>
using namespace std;
class Solution {
  public:
    int maxArea(vector<int> &heights) {
        int max = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right) {
            int curr = 0;
            if (heights[left] > heights[right]) {
                curr = heights[right] * (right - left);
                --right;
            } else {
                curr = heights[left] * (right - left);
                ++left;
            }

            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
};
