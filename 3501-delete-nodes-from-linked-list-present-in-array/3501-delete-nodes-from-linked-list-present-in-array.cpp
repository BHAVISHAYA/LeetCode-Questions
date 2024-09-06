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
    ListNode* reverse(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while(curr != NULL) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
        return head;
    }
    void insertAtHead(ListNode* &head, int data) {
        ListNode* newNode = new ListNode(data);
        if(head == NULL) { 
            head = newNode;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> m;
        for(auto &value : nums) {
            m[value]++;
        }
        ListNode* temp = head;
        ListNode* HEAD = NULL;
        while(temp != NULL) {
            if(m[temp -> val] == 0) {
                insertAtHead(HEAD, temp -> val);
            }
            temp = temp -> next;
        }
        return reverse(HEAD);
    }
};