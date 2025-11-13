/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* h1 = new ListNode(0);
        ListNode* t1 = h1;
        ListNode* h2 = new ListNode(0);
         ListNode* t2 = h2;
        while(temp != NULL){
            if(temp->val < x){
                t1->next = temp;
                temp = temp->next;
                t1 = t1->next;
                t1->next = NULL;
            }
            else{
                t2->next = temp;
                temp = temp->next;
                t2 = t2->next;
                t2->next = NULL;
            }
        }
        t1 = h1;
        while(t1->next != NULL){
            t1 = t1->next;
        }
        t1->next = h2->next;
        return h1->next;
    }
};