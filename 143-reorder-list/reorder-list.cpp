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
    void reorderList(ListNode* head) {
        // find middle using slow/fast method
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* curr = slow->next;
        slow->next = nullptr; // cut list in half
        
        ListNode* prev = nullptr;
        ListNode* next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // interleave nodes
        ListNode* reorder = prev;
        while (reorder) {
            next = reorder->next;

            reorder->next = head->next;
            head->next = reorder;

            head = reorder->next;
            reorder = next;
        }
    }
};