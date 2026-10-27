class Solution {
public:
    int d = 0;

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = height(root->left);
        int r = height(root->right);

        d = max(d, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return d;
    }
};