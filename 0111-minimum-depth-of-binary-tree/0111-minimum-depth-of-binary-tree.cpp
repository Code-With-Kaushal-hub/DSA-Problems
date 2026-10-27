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
   int mi=INT_MAX;
    void pre(TreeNode* root,int n){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            mi=min(mi,n+1);
            return ;
        }
        
        pre(root->left,n+1);
        pre(root->right,n+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        pre(root,0);
        return mi;
    }
};