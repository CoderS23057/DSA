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
ListNode*reverse(ListNode*head){
    ListNode*prev = NULL;
    while(head){
        ListNode*future = head->next;
        head->next = prev;
        prev = head;
        head = future;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode*first = head;
        ListNode*second = slow->next;
        while(second){
            if(first->val != second->val){
                return false;
            }
            first=first->next;
            second= second->next;
        }
        return true;
    }
};