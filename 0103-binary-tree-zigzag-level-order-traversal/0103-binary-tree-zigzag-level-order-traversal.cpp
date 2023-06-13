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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;

         if(!root) return ans;

         deque<TreeNode*> dq;

        dq.push_back(root);

         bool flag = true;

         while(!dq.empty()){
             int n = dq.size();
             vector<int> level;

             if(flag == true){
                for(int i=0;i<n;i++){
                     TreeNode* temp = dq.front();
                    dq.pop_front();

                    if(temp->left != NULL){
                        dq.push_back(temp->left);
                    }
                    if(temp->right != NULL){
                        dq.push_back(temp->right);
                    }
                    level.push_back(temp->val);
                }
                flag = !flag;
             }
             else{
                for(int i=0;i<n;i++){
                    TreeNode* temp = dq.back();
                    dq.pop_back();

                    if(temp->right != NULL){
                        dq.push_front(temp->right);
                    }
                    if(temp->left != NULL){
                        dq.push_front(temp->left);
                    }
                    level.push_back(temp->val);
                }  
                flag = !flag;               
             }

             ans.push_back(level);
         }

         return ans;

    }
};