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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* insert = head;
        ListNode* prev = head->next;
        ListNode* traverse = prev->next;
        bool odd = true;
        while (traverse) {
            if (odd) {
                prev->next = traverse->next;
                traverse->next = insert->next;
                insert->next = traverse;
                insert = traverse;
                traverse = prev->next;
            }
            else {
                prev = traverse;
                traverse = traverse->next;
            }
            odd = !odd;
        }
        return head;
    }
};