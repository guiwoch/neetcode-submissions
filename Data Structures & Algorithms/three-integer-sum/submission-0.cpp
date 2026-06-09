#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int target = nums[i] * -1;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    solution.push_back({nums[i], nums[left], nums[right]});
                    skip_left(nums, left);
                    skip_right(nums, right);
                } else if (sum < target) {
                    skip_left(nums, left);
                } else {
                    skip_right(nums, right);
                }
            }
        }
        return solution;
    }

  private:
    void skip_left(const vector<int> &nums, int &left) {
        while (left + 1 < nums.size() && nums[left] == nums[left + 1])
            ++left;
        ++left;
    }

    void skip_right(const vector<int> &nums, int &right) {
        while (right - 1 >= 0 && nums[right] == nums[right - 1])
            --right;
        --right;
    }
};