/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    vector<vector<int>> solution;

  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        auto helper = [&](auto &&self, queue<TreeNode *> &frontier) -> void {
            vector<int> level;
            queue<TreeNode *> new_frontier;
            while (!frontier.empty()) {
                level.push_back(frontier.front()->val);
                if (frontier.front()->left) {
                    new_frontier.push(frontier.front()->left);
                }
                if (frontier.front()->right) {
                    new_frontier.push(frontier.front()->right);
                }
                frontier.pop();
            }
            solution.push_back(level);
            if (!new_frontier.empty()) {
                self(self, new_frontier);
            }
        };
        queue<TreeNode *> frontier;
        if (root) {
            frontier.push(root);
            helper(helper, frontier);
        }
        return solution;
    }
};