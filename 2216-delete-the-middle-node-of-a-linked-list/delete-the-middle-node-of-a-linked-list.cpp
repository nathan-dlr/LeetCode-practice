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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 0;
        ListNode* node_traverse = head;
        while (node_traverse != nullptr) {
            size++;
            node_traverse = node_traverse->next;
        }
        if (size == 1) {
            return nullptr;
        }
        node_traverse = head;
        for (int i = 0; i < (size/2)-1; i++){
            node_traverse = node_traverse->next;
        }
        ListNode* nxt_node;
        nxt_node = (node_traverse->next)->next;
        node_traverse->next = nxt_node;
        return head;
    }
};