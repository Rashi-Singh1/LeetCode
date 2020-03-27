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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while(l1 &&  l2){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum%=10;
            l1->val = sum;
            l2->val = sum;
            if(l1->next == NULL && l2->next == NULL){
                if(carry == 1) l1->next = new ListNode(1);
                return head1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            sum%=10;
            l1->val = sum;
            if(carry == 1 && l1->next == NULL) {
                carry = 0;
                l1->next = new ListNode(1);
            }
            l1 = l1->next;
            if(l1 == NULL) {
                return head1;
            }
        }
        while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            sum%=10;
            l2->val = sum;
            if(carry == 1 && l2->next == NULL) {
                carry = 0;
                l2->next = new ListNode(1);
            }
            l2 = l2->next;
            if(l2 == NULL) {
                return head2;
            }
        }
        return NULL;
    }
};