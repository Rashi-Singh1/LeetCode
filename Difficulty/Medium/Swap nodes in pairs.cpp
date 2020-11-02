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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode* prev = NULL, *cur = head, *nex = head->next;
        head = head->next;
        while(cur){
            cur->next = nex == NULL ? NULL: nex->next;
            if(nex) nex->next = cur;
            prev = cur;
            cur = cur->next;
            nex = cur == NULL ? NULL : cur->next;
            if(nex) prev->next = nex;
        }
        return head;
    }
};