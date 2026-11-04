/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
 string ans="";
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;

        }
         ans+=to_string(root->val)+",";
        inorder(root->left);
       
        inorder(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        inorder(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* insertnode(int x,TreeNode* head){
        if(head==NULL){
            TreeNode* new_node= new TreeNode(x);
            return new_node;
        }
        
         if(x>head->val){
            head->right=insertnode(x,head->right);
         }
         else{
            head->left=insertnode(x,head->left);
         }
         return head;
    }
    TreeNode* deserialize(string data) {
         TreeNode* head=NULL;
         string p="";
          for(char i:data){
            if(i!=','){
                p+=i;
            }
            else{
                int x=stoi(p);
                head=insertnode(x,head);
                p="";
            }  
           
          }
          return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;