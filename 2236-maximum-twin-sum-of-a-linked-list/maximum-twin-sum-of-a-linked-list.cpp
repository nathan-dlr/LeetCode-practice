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
 ListNode* ReverseHalf(ListNode* head, ListNode* stop) {
    if (head->next == stop) {
        return head;
    }
    else {
        ListNode* ReversedHead = ReverseHalf(head->next, stop);
        head->next->next = head;
        head->next = nullptr;
        return ReversedHead;
    }
}

class Solution {
public:
    int pairSum(ListNode* head) {
        int max = 0;
        int curr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        head = ReverseHalf(head, slow);
        while (slow != nullptr) {
            curr = slow->val + head->val;
            if (curr > max) {
                max = curr;
            }
            slow = slow->next;
            head = head->next;
        }
        return max;

    }
};

