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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* i=NULL;
         ListNode* pre=NULL;
        while(temp!=NULL&&temp->val<x){
            i=temp;
            pre=temp;
            temp=temp->next;
        
        }
        while(temp!=NULL){
            if(temp->val<x){
                ListNode* next = temp->next;
               pre->next=temp->next;
               if(i==NULL){
                temp->next=head;
                head=temp;
                i=head;
               }
               else{
               temp->next=i->next; 
               i->next=temp;}
               i=temp;
               temp=next;
            }
            else{
            pre=temp;
            temp=temp->next;}
        }
        return head;
    }
};