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
        int ct = 0;
        ListNode* temp = head; 
        while(temp != NULL) {
            ct++;
            temp = temp -> next;
        }
        return ct;
    }
    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int mid = (len / 2);
        ListNode* temp = head; 
        while(mid != 0) {
            mid--;
            temp = temp -> next; 
        }
        return temp;
   }
};