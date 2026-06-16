// Permutation in String
#include <array>
#include <string>
class Solution {
  public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::array<int, 26> count{};
        for (int ch : s1) {
            count[ch - 'a']++;
        }

        std::array<int, 26> window{};
        for (int i = 0; i < s1.size(); ++i) {
            window[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size() + 1; ++i) {
            if (count == window) {
                return true;
            }
            window[s2[i] - 'a']--;
            window[s2[i + s1.size()] - 'a']++;
        }
        return false;
    }
};
