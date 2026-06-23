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
        // need access to node 0 and node n
        // niave aproach, traverse LL, for every other node insert the tail - O(N^2)
        // O(N) approach, store each node in a vector, that way we have easier access to the back of the list
        // Fill vector of nodes
        std::vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        
        if (nodes.size() <= 2) {
            return;
        }
        // traverse the vector, removing the last and inserting it between nodes
        int i;
        for (i = 0; i < nodes.size() - 2; i++) {
            ListNode* insert = nodes.back();
            nodes.pop_back();
            insert->next = nodes[i]->next;
            nodes[i]->next = insert;
        }

        // Close the linked list with null ptr
        if (i == nodes.size() - 2) {
            nodes[i+1]->next = nullptr;
            return;
        }
        else if (i == nodes.size() - 1) {
            nodes[i]->next = nullptr;
            return;
        }
    }
};