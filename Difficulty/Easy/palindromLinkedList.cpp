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
    ListNode* getReverse(ListNode* cur){
        if(cur == NULL) return cur;
        ListNode *prev = NULL, *next = cur->next;
        while(cur){
            cur->next = prev;
            prev = cur;
            cur = next;
            next = cur == NULL ? NULL : cur->next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* A) {
        if(A == NULL || A->next == NULL) return true;
        ListNode *cur = A, *prev = NULL;

        long long int size = 0;
        while(cur){
            cur = cur->next;
            size++;
        }
        
        size =(size+1ll)/2ll;
        cur = A;
        while(size > 0){
            size--;
            prev = cur;
            cur = cur->next;
        }
        
        cur = getReverse(cur);
        if(prev) prev->next = cur;
        
        while(A && cur){
            if(A->val != cur->val) return false;
            cur = cur->next;
            A = A->next;
        }
        return true;
    }
};