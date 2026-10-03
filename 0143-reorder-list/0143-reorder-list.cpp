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
    void reorderList(ListNode* head) {
         vector<int> a;
        ListNode*p=head;
        while(p!=NULL){
            a.push_back(p->val);
            p=p->next;
        }
        ListNode*temp=head;
        int n=a.size();
        int i=0;
        int j=n-1;
        if(n%2==0){
            while(i<j){
                temp->val=a[i];
                temp=temp->next;
                temp->val=a[j];
                temp=temp->next;
                i++;
                j--;
            }
        }
        else{
             while(i<j){
                temp->val=a[i];
                temp=temp->next;
                temp->val=a[j];
                temp=temp->next;
                i++;
                j--;
            }
            temp->val=a[i];
        }
        
    }
};