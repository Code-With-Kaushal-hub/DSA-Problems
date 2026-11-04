class Solution {
public:
    TreeNode* prev = NULL;

    void preorder(TreeNode* root) {
        if(root == NULL) return;

        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if(prev != NULL) {
            prev->right = root;
            prev->left = NULL;
        }

        prev = root;

        preorder(l);
        preorder(r);
    }

    void flatten(TreeNode* root) {
        prev = NULL;
        preorder(root);
    }
};