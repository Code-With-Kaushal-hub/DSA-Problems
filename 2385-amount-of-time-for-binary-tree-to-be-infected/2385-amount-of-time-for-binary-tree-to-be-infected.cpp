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
     map<TreeNode*,TreeNode*>m;
    queue<TreeNode*>q;
     map<TreeNode*,bool>visit;
    void inorder(TreeNode* root,TreeNode*p,int target){
        if(root==NULL){
            return;
        }
        inorder(root->left,root,target);
        m[root]=p;
        if(root->val==target){
            q.push(root);
            visit[root]=true;
        }
        else{
            visit[root]=false;
        }
        inorder(root->right,root,target);
    }
    int amountOfTime(TreeNode* root, int start) {
        int count=0;
        // code here
       
        inorder(root,NULL,start);
        while(!q.empty()){
            
               int sz=q.size();
                for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                TreeNode*par=m[node];
                if(par!=NULL&&visit[par]==false){
                    q.push(par);
                    visit[par]=true;
                }
                if(node->left!=NULL&&visit[node->left]==false){
                    q.push(node->left);
                    visit[node->left]=true;
                }
                if(node->right!=NULL&&visit[node->right]==false){
                    q.push(node->right);
                    visit[node->right]=true;
                }}
            count++;
        }
        return count-1;
        
    }
};