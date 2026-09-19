/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
        Node*temp=head;
         Node* dumy= new Node(-1);
         Node* ans=dumy;
        while(temp!=NULL){
            Node* newnode= new Node(temp->val);
            dumy->next=newnode;
            m[temp]=newnode;
            dumy=dumy->next;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }
        ans=ans->next;
        return ans;
        
    }
};