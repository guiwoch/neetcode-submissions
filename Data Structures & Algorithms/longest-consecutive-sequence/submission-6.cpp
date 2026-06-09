#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> hashSet;
        for (const int num : nums) {
            hashSet.insert(num);
        }
        for (const int num : hashSet) {
            if (!hashSet.contains(num - 1)) {
                int curr = 1;
                int i = 1;
                while (hashSet.contains(num + i)) {
                    ++curr;
                    ++i;
                }
                if (curr > longest) {
                    longest = curr;
                }
            }
        }
        return longest;
    }
};
