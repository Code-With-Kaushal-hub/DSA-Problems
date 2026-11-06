class Solution {
public:
    vector<vector<int>> ans;

    void pre(TreeNode* root, int targetSum, int sum, vector<int>& t) {

        if(root == NULL) {
            return;
        }

        t.push_back(root->val);
        sum += root->val;

        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                ans.push_back(t);
            }
        }

        pre(root->left, targetSum, sum, t);
        pre(root->right, targetSum, sum, t);

        t.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> t;

        pre(root, targetSum, 0, t);

        return ans;
    }
};