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

    ListNode* insert(ListNode* &head, ListNode* &tail, int data) {
        ListNode* newNode = new ListNode(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        return head;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        if(k == 1) {
            ans.push_back(head);
            return ans;
        }
        int len = getLength(head);
        if(k >= len) {
            ListNode* temp = head;
            while(temp != NULL) {
                ListNode* tmp = new ListNode(temp -> val);
                ans.push_back(tmp);
                temp = temp -> next;
            }
            k = k - len;
            while(k--) {
                ListNode* tmp = NULL;
                ans.push_back(tmp);
            }
        }
        else {
            int partLen = len / k;
            int extraOneTObeAdded = len % k;
            int K;
            if(extraOneTObeAdded == 0)
            K = partLen;
            else 
            K = partLen + 1; 
            int cntExtra = 0;
            ListNode* temp = head;
            jump:
                int ct = 0;
                ListNode* HEAD = NULL;
                ListNode* TAIL = NULL;
                while(temp != NULL) {
                    ct++;
                    HEAD = insert(HEAD, TAIL, temp -> val);
                    temp = temp -> next;
                    if(ct == K) {
                        ans.push_back(HEAD);
                        cntExtra++;
                        if(cntExtra == extraOneTObeAdded)
                        K = K - 1;
                        goto jump;
                    }
                }
        }
        return ans;
    }
};