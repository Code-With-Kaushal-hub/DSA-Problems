class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        ListNode* temp;

        if (list1->val <= list2->val) {
            temp = list1;
            list1 = list1->next;
        }
        else {
            temp = list2;
            list2 = list2->next;
        }

        ListNode* head = temp;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            temp->next = list1;
            temp = temp->next;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            temp->next = list2;
            temp = temp->next;
            list2 = list2->next;
        }

        return head;
    }


    ListNode* mergeSort(ListNode* head) {

        // 0 or 1 node
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both halves
        ListNode* first = mergeSort(head);
        second = mergeSort(second);

        // Merge both sorted halves
        return mergeTwoLists(first, second);
    }


    ListNode* sortList(ListNode* head) {

        return mergeSort(head);
    }
};