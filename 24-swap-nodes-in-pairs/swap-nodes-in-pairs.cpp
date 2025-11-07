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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fut =  NULL;
        ListNode* temp = head;
        int count = 0;
        while(count<2){
            if(temp==NULL){   //if <2 node don,t reverse
                return head;
            }
            temp = temp->next;
            count++;
        }
        count = 0;
        while(curr && count<2){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            count++;
        }
        head->next= swapPairs(curr);
        return prev;
    }
};