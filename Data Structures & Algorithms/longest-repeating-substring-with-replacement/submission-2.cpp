// Longest Repeating Character Replacement
#include <array>
#include <string>
class Solution {
  public:
    int characterReplacement(std::string s, int k) {
        std::array<int, 26> count{};
        int res = 0 ;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            ++count[s[right] - 'A'];
            while (right - left + 1 -
                       *std::max_element(count.begin(), count.end()) > k) {
                --count[s[left] - 'A'];
                ++left;
            }
            res = std::max(res, right - left + 1);
        }
        return res;
    }
};