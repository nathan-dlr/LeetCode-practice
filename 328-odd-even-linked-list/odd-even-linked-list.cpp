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
        ListNode* oddTraverse = new ListNode;
        ListNode* oddHead = new ListNode;
        ListNode* evenTraverse = new ListNode;
        ListNode* evenHead = new ListNode;
        int count = 1;
        if (head == nullptr) {return nullptr;}

        while (head != nullptr) {
            if (count % 2 == 0) {
                if (count != 2) {
                    evenTraverse->next = head;
                    evenTraverse = evenTraverse->next;
                }
                else {
                    evenTraverse->next = head;
                    evenHead = evenTraverse->next;
                    evenTraverse = evenTraverse->next;
                }
            }
            else {
                if (count != 1) {
                    oddTraverse->next = head;
                    oddTraverse = oddTraverse->next;
                }
                else {
                    oddTraverse->next = head;
                    oddHead = oddTraverse->next;
                    oddTraverse = oddTraverse->next;
                }
            }
            head = head->next;
            count++;
        }
        if (count == 2) {return oddHead;}
        evenTraverse->next = nullptr;
        oddTraverse->next = evenHead;
        return oddHead;
    }
};