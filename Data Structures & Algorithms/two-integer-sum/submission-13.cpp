#include <unordered_map>
#include <vector>
class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            if (auto it = map.find(target - nums[i]); it != map.end()) {
                return std::vector<int>{it->second, i};
            }
            map[nums[i]] = i;
        }
    }
};
