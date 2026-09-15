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
    void insertAtEnd(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        int carry=0;
        int val;

        while(l1!=NULL&& l2!=NULL){
            
            int p=l1->val+l2->val+carry;
            
            val=p%10;
            carry=p/10;
          
           
           
            
            insertAtEnd(head,val);
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
             int p=l1->val+carry;
        
                val=p%10;
                carry=p/10;
            
            l1=l1->next;
            insertAtEnd(head,val);
        }
        while(l2!=NULL){
             int p=l2->val+carry;
                            val=p%10;
                carry=p/10;
            
            l2=l2->next;
            insertAtEnd(head,val);
        }
        if(carry!=0){
             insertAtEnd(head,carry);
        }
        return head;
    }
};