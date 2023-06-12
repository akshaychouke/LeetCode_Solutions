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
    bool check(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL || root2 == NULL){
            return root1 == root2; // if both are null then it will return true otherwise return false;
        }

        // left root data should be same as right root data
        bool con1 = (root1->val == root2->val);

        // to check for mirror
        
        //to check whether root1 left node is equal to root2 right node 
        bool con2 = check(root1->left,root2->right);

        //to check whether root1 right node is equal to root2 left node 
        bool con3 = check(root1->right,root2->left);

        return (con1 && con2 && con3);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return check(root->left,root->right);
    }
};