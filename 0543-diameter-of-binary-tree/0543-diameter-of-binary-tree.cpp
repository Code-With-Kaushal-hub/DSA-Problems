class Solution {
public:

    int dfs(TreeNode* root, int count) {
        if (root == NULL) {
            return count;
        }

        int l = dfs(root->left, count + 1);
        int r = dfs(root->right, count + 1);

        return max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        int l = 0;
        int r = 0;

        if (root->left != NULL)
            l = dfs(root->left, 0);

        if (root->right != NULL)
            r = dfs(root->right, 0);

        int ans = l + r;

        // Check diameter inside left subtree
        if (root->left != NULL)
            ans = max(ans, diameterOfBinaryTree(root->left));

        // Check diameter inside right subtree
        if (root->right != NULL)
            ans = max(ans, diameterOfBinaryTree(root->right));

        return ans;
    }
};