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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k ==0) return head;
        
        vector<int>ans;
        ListNode*temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n = ans.size();
        temp = head;
        k = k%n;
        for(int i = n-k; i<n;i++){
            temp->val = ans[i];
            temp = temp->next;
        }
        for(int i = 0;i<n-k;i++){
            temp->val = ans[i];
            temp = temp->next;
        }
        return head;
    }
};