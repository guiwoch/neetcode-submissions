// 018.cpp Search a 2D Matrix
#include <vector>
using namespace std;
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int max = rows * columns;
        int left = 0, right = max - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int row_idx = mid / columns;
            int column_idx = mid % columns;
            if (matrix[row_idx][column_idx] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (matrix[left / columns][left % columns] == target)
            return true;
        return false;
    }
};