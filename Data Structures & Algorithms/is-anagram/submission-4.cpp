#include <string>

class Solution {
  public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int count[26]{};
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : t) {
            if (--count[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
