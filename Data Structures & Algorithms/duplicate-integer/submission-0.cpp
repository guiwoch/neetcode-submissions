#include <functional>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    bool hasDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> hashSet;
        hashSet.reserve(nums.size());

        for (auto i : nums) {
            if (hashSet.contains(i)) {
                return true;
            }
            hashSet.insert(i);
        }
        return false;
    }
};
