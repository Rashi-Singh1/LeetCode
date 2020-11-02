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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        int sizea = 0, sizeb = 0;
        while(cur){
            cur = cur->next;
            sizea++;
        }
        cur = headB;
         while(cur){
            cur = cur->next;
            sizeb++;
        }
        if(sizea > sizeb){
            while(sizea >  sizeb && headA){
                headA = headA->next;
                sizea--;
            }
        }
        else if(sizeb >  sizea){
             while(sizea < sizeb && headB){
                headB = headB->next;
                sizeb--;
            }
        }
        if(sizea != sizeb) return NULL;
        while(headA && headB){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};