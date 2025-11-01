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
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=head;
        ListNode* d=dummy;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        while(temp){
            int value=temp->val;
            if(s.find(value)!=s.end()){
                temp=temp->next;
                d->next=temp;
            }
            else{
                temp=temp->next;
                d=d->next;
            }
        }
        return dummy->next;
    }
};