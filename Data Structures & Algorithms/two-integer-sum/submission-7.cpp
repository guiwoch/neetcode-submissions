#include <unordered_map>
#include <vector>
class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (auto it = map.find(target - nums[i]); it != map.end()) {
                if (i != it->second) {
                    return std::vector<int>{i, it->second};
                }
            }
        }
        return std::vector<int>{0, 0};
    }
};
