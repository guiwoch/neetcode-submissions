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
    std::pair<bool, int> helper(TreeNode *node) {
        if (!node) {
            return {true, 0};
        }
        auto [l_bool, l_height] = helper(node->left);
        auto [r_bool, r_height] = helper(node->right);
        bool balanced = l_bool && r_bool && std::abs(l_height - r_height) <= 1;
        return {balanced, std::max(l_height, r_height) + 1};
    }

  public:
    bool isBalanced(TreeNode *root) {
        return helper(root).first;
    }
};
