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
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* evenHead=NULL,*evenTail=NULL,*oddHead=NULL,*oddTail=NULL,*curr=head;
        int i=1;
        while(curr!=NULL){
            if(i%2==0){
                if(evenHead==NULL){
                    evenHead=evenTail=curr;
                }
                else{
                    evenTail->next=curr;
                    evenTail=evenTail->next;
                }
            }
            else{
                if(oddHead==NULL){
                    oddHead=oddTail=curr;
                }
                else{
                    oddTail->next=curr;
                    oddTail=oddTail->next;
                }
            }
            i++;
            curr=curr->next;
        }
        if(oddHead==NULL){
            evenTail->next=NULL;
            return evenHead;
        }
        oddTail->next=evenHead;
        if(evenHead!=NULL){
            evenTail->next=NULL;
        }
        
        return oddHead;
        
    }
};