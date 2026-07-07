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
    int t=1;
    int inorder(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int a=inorder(root->left)+1;
        int b=inorder(root->right)+1;
        if(abs(a-b)>1){
            t=0;
        }
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        int x=inorder(root);
        return t;
    }
};