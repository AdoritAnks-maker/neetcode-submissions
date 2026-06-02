class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->next;  
            curr->next = prev;  
            prev = curr;        
            curr = temp;      
        }

        return prev;
    }
};