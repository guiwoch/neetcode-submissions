// Search in Rotated Sorted Array
#include <vector>
using namespace std;
class Solution {
    int find_min(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[nums.size() - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

  public:
    int search(vector<int> &nums, int target) {
        int min_idx = find_min(nums);
        int left, right;
        if (target <= nums[nums.size() - 1]) {
            left = min_idx, right = nums.size() - 1;
        } else {
            left = 0, right = min_idx - 1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};