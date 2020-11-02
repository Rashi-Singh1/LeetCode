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
private:
    int ans = 0;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int left = solve(root->left), right = solve(root->right);
        ans = max(ans, left + right);
        return max(left, right)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        solve(root);
        return ans;
    }
};