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
    bool Solve(TreeNode* root,int sum){
        if(root == NULL) return false;
        if(root->val == sum && root->left == NULL && root->right == NULL) return true;
        sum -=root->val;
        bool leftPart = Solve(root->left,sum);
        bool rightPart = Solve(root->right,sum);
        return leftPart||rightPart;   //if anyone of the subtree returns true then ans is true;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return Solve(root,targetSum);        
    }
};