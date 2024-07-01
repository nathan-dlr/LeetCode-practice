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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == nullptr) {
            return head;
        }
        else {  
            ListNode* node = reverseList(head->next);
            ListNode* copy = node;
            while (copy->next != nullptr) {
                copy = copy->next;
            }
            copy->next = head;
            copy->next->next = nullptr;
            return node;
        
        }
        
    }
};