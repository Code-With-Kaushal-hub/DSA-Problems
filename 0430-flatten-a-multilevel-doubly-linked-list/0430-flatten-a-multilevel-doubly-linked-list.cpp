/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* fun(Node* head) {
        if(head==NULL||(head->next==NULL&&head->child==NULL)){
            if(head!=NULL){
                head->child=NULL;
            }
            return head;
        }
        cout<<head->val<<" ";
        if(head->child==NULL){
            return fun(head->next);
        }
        else{
        Node* temp=head->next;
        Node* temp2=fun(head->child);
        head->next=head->child;
        head->child=NULL;
        head->next->prev=head;
        if(temp != NULL) {
                temp->prev = temp2;
                temp2->next = temp;
        }
        return fun(head->next);
        
        }
        
        return head ;

    }
    Node* flatten(Node* head) {
        Node* temp=fun(head);
        return head;
        

    }
};