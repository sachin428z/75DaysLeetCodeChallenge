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
    int sizeList(ListNode* head) {
        int size=0;
        while(head) {
            head=head->next;
            size++;
        }
    return size;
}

    int pairSum(ListNode* head) {
        stack<int> st;
        int n=sizeList(head);
        int i=0;
        while(i<n/2) {
            st.push(head->val);
            head=head->next;
            i++;
        }
        int maxSum=0;
        while(head) {
            maxSum=max(head->val+st.top(),maxSum);
            head=head->next;
            st.pop();
        }
        return maxSum;
    }
};