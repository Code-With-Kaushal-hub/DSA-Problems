/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }
        TreeNode* l=dfs(root->left,p,q);
        TreeNode* r=dfs(root->right,p,q);
        if(l&&r){
            return root;
        }
        if(l){
            return l;
        }
        if(r){
            return r;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        return dfs(root,p,q);
    }
};