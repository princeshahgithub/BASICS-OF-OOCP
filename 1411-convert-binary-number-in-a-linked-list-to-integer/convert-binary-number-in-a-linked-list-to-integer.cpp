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
    int getDecimalValue(ListNode* head) {
        int count = 1;  // Initialize power multiplier
        int num = 0;
        ListNode* cur = head;

        // First pass: determine length and set initial power of 2
        while (cur != nullptr) {
            cur = cur->next;
            count *= 2;
        }

        count /= 2;  // Adjust back by one power
        cur = head;

        // Second pass: compute decimal value
        while (cur != nullptr) {
            num += cur->val * count;
            count /= 2;
            cur = cur->next;
        }

        return num;
    }
};