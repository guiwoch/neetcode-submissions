class Solution {
    vector<int> solution;

  public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> queue;
        if (root){
            queue.push(root);
        }
        while (!queue.empty()) {
            int level_size = queue.size();
            for (int i = 0; i < level_size; ++i){
                if (queue.front()->left){
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right){
                    queue.push(queue.front()->right);
                }
                if (i == level_size - 1){
                    solution.push_back(queue.front()->val);
                }
                queue.pop();
            }
        }
        return solution;
    }
};
