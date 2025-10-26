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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retList = new ListNode();
        ListNode* retWriter = retList;
        bool overflow = false;
        while (l1 || l2 || overflow) {
            int val = 0; 
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            if (overflow) {
                val++;
            }
            if (val > 9) {
                overflow = true;
                val -= 10;
            }
            else {
                overflow = false;
            }
            retWriter->val = val;
            if (l1 || l2 || overflow) {
                retWriter->next = new ListNode();
                retWriter = retWriter->next;
            }
        }
        return retList;
    }
};