class Solution {
    vector<int> solution;

  public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> q;
        if (root){
            q.push(root);
        }
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i){
                if (q.front()->left){
                    q.push(q.front()->left);
                }
                if (q.front()->right){
                    q.push(q.front()->right);
                }
                if (i == level_size - 1){
                    solution.push_back(q.front()->val);
                }
                q.pop();
            }
        }
        return solution;
    }
};
