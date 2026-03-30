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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return NULL;
        unordered_map<int,int> mp;
        for(auto x:nums) {
            mp[x]++;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* temp=head;
        while(temp) {
            if(mp.count(temp->val)) {
                prev->next=temp->next;
                temp=prev->next;
            } else {
                prev=temp;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};