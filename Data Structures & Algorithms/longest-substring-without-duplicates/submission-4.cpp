#include <string>
#include <unordered_set>
class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<int> hash_set;
        int left = 0;
        int max = 0;
        for (int right = 0; right < s.size(); ++right) {
            while (hash_set.contains(s[right])) {
                hash_set.erase(s[left]);
                ++left;
            }
            hash_set.insert(s[right]);
            max = std::max(max, right - left + 1);
        }
        return max;
    }
};