
class Solution {
public:
    TreeNode *helper(int preleft,int preright,
                     int inleft,int inright,
                     map<int,int>&m,
                     vector<int>& preorder,
                     vector<int>& inorder) {

        if(preleft>preright || inleft>inright){
            return NULL;
        }

        int n=m[preorder[preleft]];

        TreeNode *new_node=new TreeNode(preorder[preleft]);

        new_node->left=helper(preleft+1,
                              preleft+n-inleft,
                              inleft,n-1,
                              m,preorder,inorder);

        new_node->right=helper(preleft+n-inleft+1,
                               preright,
                               n+1,inright,
                               m,preorder,inorder);

        return new_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int,int>m;

        int j=0;

        for(int i:inorder){
            m[i]=j;
            j++;
        }

        return helper(0,preorder.size()-1,
                      0,inorder.size()-1,
                      m,preorder,inorder);
    }
};
