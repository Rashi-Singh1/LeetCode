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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int size = 0;
        ListNode* cur = head;
        while(cur){
            size++;
            cur = cur->next;
        }
        if(size == 1 && n == 1) return NULL;
        size = size - n;
        if(size == 0) return head->next;
        cur = head;
        while(cur){
            size--;
            if(size == 0){
                if(cur->next) cur->next = cur->next->next;
                return head;
            }  
            cur = cur->next;
        }
        return head;
    }
};