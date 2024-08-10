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
    int getLength(ListNode* &head) {
        ListNode* temp = head;
        int ct = 0;
        while(temp != NULL) {
            ct++;
            temp = temp -> next;
        }
        return ct;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k > getLength(head)) return head;
        if(head == NULL) return NULL;

        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        int ct = 0;
        while(curr != NULL && ct < k) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            ct++;
        }

        if(forward != NULL) {
            if(getLength(forward) < k) 
            head -> next = forward;
            else 
            head -> next = reverseKGroup(forward, k);
        }

        head = prev;
        return head;
    }
};