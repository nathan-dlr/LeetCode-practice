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
        std::stack<ListNode*> nodes;
        ListNode* traverse = head;
    
        while (traverse) {
            nodes.push(traverse);
            traverse = traverse->next;
        }

        if (n == nodes.size()) {
            return head->next;
        }

        ListNode* next = nullptr;
        for (int i = 0; i < n - 1; i++) {
            next = nodes.top();
            nodes.pop();
        }

        nodes.pop();
        nodes.top()->next = next;
        return head;
    }
};