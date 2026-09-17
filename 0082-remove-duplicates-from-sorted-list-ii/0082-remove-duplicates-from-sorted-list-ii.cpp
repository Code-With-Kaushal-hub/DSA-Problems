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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* pre=NULL;
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast!=NULL){
            if((slow->val==fast->val)){
            while(fast!=NULL&&slow->val==fast->val){
        
                fast=fast->next;
                
            }
            slow=fast;
            if(pre==NULL){
                head=fast;
            }
            else{
                pre->next=slow;
            }
            if(fast==NULL){
                return head;
            }
            fast=slow->next;
            }
            else{
                pre=slow;
                slow=fast;
                fast=fast->next;
            }

        }
        return head;
    }
};