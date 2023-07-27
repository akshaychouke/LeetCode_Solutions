/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        map<ListNode*,bool> mpp;

        while(h1 != NULL || h2 != NULL){
            if(h1 == h2) return h1;
            if(mpp[h1] == true) return h1;
            if(mpp[h2] == true) return h2;

            if(h1 != NULL) mpp[h1] = true;
            if(h2 != NULL) mpp[h2] = true;

            if(h1 != NULL){
                h1 = h1->next;
            }
            else{
                mpp[h1] = false;
            }

            if(h2 != NULL){
                h2 = h2->next;
            }
            else{
                mpp[h2] = false;
            }
        }

        return NULL;
    }
};