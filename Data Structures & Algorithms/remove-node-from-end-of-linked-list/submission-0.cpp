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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lentt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            lentt++;
            temp = temp->next;
        }
        int target = lentt - n + 1;
        if (target == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        temp = head;
        for (int i = 1; i < target-1; i++) {
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next= temp->next->next;
        delete del;
        return head;
    }
};