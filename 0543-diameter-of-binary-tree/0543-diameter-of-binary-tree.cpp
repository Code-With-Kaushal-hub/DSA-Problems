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
public:
    int maxi=0;
    int inorder(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a=inorder(root->left);
        int b=inorder(root->right);
        maxi=max(maxi,a+b);
        return 1+max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int b=inorder(root);
        return maxi;
    }
};