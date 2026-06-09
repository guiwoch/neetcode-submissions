#include <vector>
using namespace std;
class Solution {
  public:
    int maxArea(vector<int> &heights) {
        int max = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right) {
            int curr = min(heights[left], heights[right]) * (right - left);
            if (curr > max)
                max = curr;
            if (heights[left] > heights[right]) --right;
            else ++left;
        }
        return max;
    }
};
