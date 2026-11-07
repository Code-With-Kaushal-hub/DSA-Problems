class Solution {
public:
    int great = INT_MIN;

    int inorder(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int l = inorder(root->left);
        int r = inorder(root->right);

        l = max(0, l);
        r = max(0, r);

        great = max(great, root->val + l + r);

        return max(l, r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int x = inorder(root);
        return great;
    }
};