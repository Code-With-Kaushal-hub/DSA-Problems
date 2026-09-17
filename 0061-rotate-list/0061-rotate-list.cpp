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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* temp2=head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        
        int n=count-k%count;
        cout<<count<<" "<<n<<endl;
        for(int i=0;i<n;i++){
            
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
            temp->next=NULL;
        }
        
        return temp2;

        
    }
};