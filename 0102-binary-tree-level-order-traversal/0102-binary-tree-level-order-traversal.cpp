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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*> q;
        if(root!=NULL){
             q.push(root);
        }
       
        while(!q.empty()){
            int s=q.size();
            int i=0;
            vector<int> ans;
            while(i<s){
                TreeNode* f=q.front();
                ans.push_back(f->val);
                q.pop();
                
                 if(f->left!=NULL){
                     q.push(f->left);
                 }
                 if(f->right!=NULL){
                     q.push(f->right);
                 }
                 i++;

            }
            vec.push_back(ans);
           
        }
        return vec;
        
    }
};