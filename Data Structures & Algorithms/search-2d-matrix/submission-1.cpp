// 018.cpp Search a 2D Matrix
#include <vector>
using namespace std;
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int max = columns * rows;
        int l = 0, r = max - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / columns][mid % columns];
            if (val == target) return true;
            if (val > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};