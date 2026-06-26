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
    int best = 0;
    int height(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int l = height(node->left);
        int r = height(node->right);
        best = std::max(best, l + r);
        return std::max(l, r) + 1;
    }

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        height(root);
        return best;
    }
};

