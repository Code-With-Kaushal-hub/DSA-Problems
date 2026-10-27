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

    bool bol=true;

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = height(root->left)+1;
        int r = height(root->right)+1;


        if(abs(l-r)>=2){
             bol=false;
        }
        return max(l,r);
    }

  
    bool isBalanced(TreeNode* root) {
        height(root);
        return bol;
    }
};