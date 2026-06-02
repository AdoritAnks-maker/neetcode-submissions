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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> mpp;
        ListNode* curr = head;
        while (curr != NULL) {
            if (mpp.find(curr) != mpp.end()) {
                return true;
            }
                mpp[curr]++;
                curr = curr->next;
        }
        return false;
    }
};
