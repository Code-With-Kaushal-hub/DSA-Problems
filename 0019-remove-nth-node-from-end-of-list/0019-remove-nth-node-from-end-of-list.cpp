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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp=head;
       int i=1;
       int len=0;
       while(temp!=NULL){
           temp=temp->next;
           len++;
       }
       temp=head;
       n=len-n+1;
       if(head==NULL&&n>=1){
        return head;
       }
       if(n==1){
           return head->next;
       }
       while(i!=n-1&&temp!=NULL){
        temp=temp->next;
        i++;
       }
       temp->next=temp->next->next;
       return head;
    }
};