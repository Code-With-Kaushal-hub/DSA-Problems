class MyLinkedList {
public:
    MyLinkedList* head = NULL;
    MyLinkedList* next = NULL;
    int val;
    int size = 0;

    MyLinkedList() {
        head = NULL;
        next = NULL;
        size = 0;
    }

    int get(int index) {

        if(index < 0 || index >= size) {
            return -1;
        }

        MyLinkedList* temp = head;
        int i = 0;

        while(temp != NULL && i != index) {
            temp = temp->next;
            i++;
        }

        return temp->val;
    }

    void addAtHead(int val) {

        MyLinkedList* temp = new MyLinkedList();

        temp->val = val;
        temp->next = head;

        head = temp;

        size++;
    }

    void addAtTail(int val) {

        MyLinkedList* newn = new MyLinkedList();

        newn->val = val;
        newn->next = NULL;

        // Empty list
        if(size == 0) {
            head = newn;
            size++;
            return;
        }

        MyLinkedList* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newn;

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) {
            return;
        }

        // Insert at beginning
        if(index == 0) {
            addAtHead(val);
            return;
        }

        // Insert at end
        if(index == size) {
            addAtTail(val);
            return;
        }

        MyLinkedList* newn = new MyLinkedList();
        newn->val = val;

        MyLinkedList* temp = head;

        int i = 0;

        // Reach node before index
        while(i < index - 1) {
            temp = temp->next;
            i++;
        }

        newn->next = temp->next;
        temp->next = newn;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) {
            return;
        }

        // Delete head
        if(index == 0) {

            MyLinkedList* temp = head;

            head = head->next;

            delete temp;

            size--;
            return;
        }

        MyLinkedList* temp = head;

        int i = 0;

        // Reach node before index
        while(i < index - 1) {
            temp = temp->next;
            i++;
        }

        MyLinkedList* del = temp->next;

        temp->next = del->next;

        delete del;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */