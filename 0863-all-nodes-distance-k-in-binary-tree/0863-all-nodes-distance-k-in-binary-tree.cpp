
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
    
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(depth(root->left), depth(root->right));
    }

    void makeParent(TreeNode* root, TreeNode* parent,
                    unordered_map<TreeNode*, TreeNode*>& mp) {
        
        if (root == NULL) {
            return;
        }

        mp[root] = parent;

        makeParent(root->left, root, mp);
        makeParent(root->right, root, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        int d = depth(root);

        // Array size of complete binary tree
        int n = pow(2, d) - 1;

        vector<TreeNode*> arr(n, NULL);

        unordered_map<TreeNode*, TreeNode*> mp;

        // Store parent of every node
        makeParent(root, NULL, mp);

        // BFS from target
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int level = 0;

        while (!q.empty() && level < k) {

            int size = q.size();

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                // Right child
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                // Parent
                if (mp[node] && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }

            level++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
