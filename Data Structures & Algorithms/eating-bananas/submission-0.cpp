// koko eating bananas
#include <vector>
using namespace std;
class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int max = 0;
        for (const int pile : piles) {
            if (pile > max)
                max = pile;
        }
        int l = 1, r = max;
        while (l < r) {
            int k = l + (r - l) / 2;
            int hours = 0;
            for (const int pile : piles) {
                hours += (pile + k - 1) / k;
            }
            if (hours <= h) {
                r = k;
            } else {
                l = k + 1;
            }
        }
        return l;
    }
};