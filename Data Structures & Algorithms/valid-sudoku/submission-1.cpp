#include <bitset>
#include <vector>
using namespace std;
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // line check
        for (const auto &line : board) {
            std::bitset<9> seen;
            for (const char &c : line) {
                if (c < '1' || c > '9') {
                    continue;
                }
                if (seen[c - '1'])
                    return false;

                seen.set(c - '1');
            }
        }

        // row check
        for (int i = 0; i < 9; ++i) {
            std::bitset<9> seen;
            for (int j = 0; j < 9; ++j) {
                const char &c = board[j][i];
                if (c < '1' || c > '9') {
                    continue;
                }
                if (seen[c - '1'])
                    return false;

                seen.set(c - '1');
            }
        }

        // matrix check
        for (int m = 0; m < 9; ++m) {
            std::bitset<9> seen;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    const char &c = board[i + (3 * (m / 3))][j + (3 * (m % 3))];
                    if (c < '1' || c > '9')
                        continue;

                    if (seen[c - '1'])
                        return false;

                    seen.set(c - '1');
                }
            }
        }
        return true;
    }
};
