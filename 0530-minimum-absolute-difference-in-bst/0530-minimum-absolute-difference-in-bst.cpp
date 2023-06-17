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
    int DFS(TreeNode* root,int &ans,int &val){
        if(root->left){
            DFS(root->left,ans,val);
        }
        if(val >= 0)
        {
            ans =min(ans,root->val - val);
            // ans = min(ans,diff);
        }

        val = root->val;

        if(root->right){
           DFS(root->right,ans,val);
           
        }
        return ans;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX,val = -1;
        return DFS(root,ans,val);
    }
};