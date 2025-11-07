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
    ListNode* reverse(ListNode* &head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut =  NULL;
        ListNode* temp = head;
        int count = 0;
        while(count<k){
            if(temp==NULL){
                return head;
            }
            temp = temp->next;
            count++;
        }
        count = 0;
        while(curr && count<k){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            count++;
        }
        head->next= reverse(curr,k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};