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
    ListNode* reverse(ListNode*head, int pos){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;
        ListNode* temp = head;
        while(pos-- && curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
            temp->next = curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        int count = 1;
        if(!head || head->next == NULL) return head;
        if(left == 1){                                 
            return reverse(head, right - left + 1);
        }
        while(count<left-1){
            temp = temp->next;
            count++;
        }
        temp->next = reverse(temp->next,right-left+1);
        return head;
    }
};