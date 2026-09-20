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
    ListNode* temp1;
    ListNode*temp2;
    int fun(ListNode* head, int k,int i){
        if(head==NULL){
            return 0;
        }
        if(i==k){
            temp1=head;
        }
        int j=1+fun(head->next,k,++i);
        if(j==k){
            temp2=head;
        }
        return j;

    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode *temp=head;
        int j=fun(temp,k,1);
        swap(temp1->val,temp2->val);
        return head;
    }
};