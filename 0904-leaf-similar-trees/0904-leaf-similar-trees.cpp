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
    void DFS(TreeNode* root,vector<int> &vec){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            vec.push_back(root->val);
        }

        DFS(root->left,vec);
        DFS(root->right,vec);    
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        DFS(root1,v1);
        DFS(root2,v2);

        return v1==v2;
    }
};