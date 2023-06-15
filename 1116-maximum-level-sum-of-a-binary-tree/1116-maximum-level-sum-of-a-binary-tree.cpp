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
    int levelOrder(TreeNode* root) {
         if(root == NULL) return 1;

         int maxi = INT_MIN;
         int level = 1;
         int result = 1;

         queue<TreeNode*> q; // to store nodes of level

         q.push(root);

         while(!q.empty()){
             int n = q.size();
             int sum = 0;
             for(int i=0;i<n;i++){
                TreeNode* temp =  q.front();
                q.pop();
                sum += temp->val;

                if(temp->left != NULL){
                    q.push(temp->left);
                 }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
             }
                if(sum > maxi ){
                    maxi = sum;
                    result = level;
                }
                level++;
             
         }

         return result;

    }
    int maxLevelSum(TreeNode* root) {
        return levelOrder(root);
    }
};