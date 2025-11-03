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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n<=0) return head; 
        ListNode*temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(n==count){
            ListNode*newnode = head;
            head = head->next;
            delete newnode;
            return head;
        }
        temp = head;
        int x = count - n;
        x--;
        while(x--){
           temp=temp->next;
        }
        ListNode*todelete = temp->next;
       temp->next = todelete->next;
        delete todelete;
        return head;
    }
};