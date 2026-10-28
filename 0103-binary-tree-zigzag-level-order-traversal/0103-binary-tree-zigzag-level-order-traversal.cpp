
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root == NULL) {
            return ans;
        }

        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> p;

            for (int i = 0; i < sz; i++) {
                TreeNode* n = q.front();
                p.push_back(n->val);
                q.pop();

                if (n->left != NULL) {
                    q.push(n->left);
                }
                if (n->right != NULL) {
                    q.push(n->right);
                }
            }

            if (level % 2 == 1) {
                reverse(p.begin(), p.end());
            }

            ans.push_back(p);
            level++;
        }

        return ans;
    }
};
