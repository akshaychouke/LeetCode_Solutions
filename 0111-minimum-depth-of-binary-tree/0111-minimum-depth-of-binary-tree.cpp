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
    int Solve(TreeNode* root){
        if(root == NULL) return 0;
        int lh = Solve(root->left);
        int rh = Solve(root->right);

        return 1+(min(lh,rh) > 0 ? min(lh,rh):max(lh,rh));

    }
    int minDepth(TreeNode* root) {
        return Solve(root);
    }
};