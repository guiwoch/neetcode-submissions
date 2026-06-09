// trapping rain water
#include <vector>
class Solution {
  public:
    int trap(std::vector<int> &height) {
        std::vector<int> max_left(height.size(), 0),
            max_right(height.size(), 0);
        int total = 0;
        max_left[0] = height[0];
        max_right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            max_right[i] = std::max(height[i], max_right[i + 1]);
        }
        for (int i = 1; i < height.size(); ++i) {
            max_left[i] = std::max(max_left[i - 1], height[i]);
            total += std::min(max_left[i], max_right[i]) - height[i];
        }
        return total;
    }
};