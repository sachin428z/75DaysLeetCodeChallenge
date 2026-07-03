/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> parts(k, nullptr);

        // Find length of linked list
        int len = 0;
        for (ListNode* node = head; node; node = node->next)
            len++;

        int n = len / k;   // Minimum nodes in each part
        int r = len % k;   // Extra nodes

        ListNode* node = head;
        ListNode* prev = nullptr;

        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;

            // Traverse current part
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }

            // Break the list
            prev->next = nullptr;
        }

        return parts;
    }
};