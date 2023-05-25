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
    void DFS(TreeNode* root,string &s){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            s.push_back(char(root->val));
        }
        DFS(root->left,s);
        DFS(root->right,s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="",s2="";

        DFS(root1,s1);
        DFS(root2,s2);
        return s1 == s2;
    }
};