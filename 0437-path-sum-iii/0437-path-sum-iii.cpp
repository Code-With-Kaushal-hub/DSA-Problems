class Solution {
public:
    int path = 0;

    void solve(TreeNode* root, long long sum) {
        if(root == NULL) {
            return;
        }

        if(sum == root->val) {
            path++;
        }

        solve(root->left, sum - root->val);
        solve(root->right, sum - root->val);
    }

    void inorder(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return;
        }

        solve(root, targetSum);

        inorder(root->left, targetSum);
        inorder(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        path = 0;
        inorder(root, targetSum);
        return path;
    }
};