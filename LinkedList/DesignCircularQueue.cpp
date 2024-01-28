class MyCircularQueue {
public:
    ListNode* head;
    ListNode* movinghead;
    ListNode* tail;
    int currsize;
    int size;
    MyCircularQueue(int k) {
        head = nullptr;
        movinghead = nullptr;
        tail = nullptr;
        currsize = 0;
        size = k;
    }

    bool enQueue(int value) {
        if (currsize == size) {
            return false;  // Queue is full.
        }
        ListNode* nextelem = new ListNode(value);
        if (currsize == 0) {
            head = nextelem;
            tail = nextelem;
        } else {
            movinghead->next = nextelem;
            tail = nextelem;
        }
        movinghead = nextelem;
        currsize++;
        return true;
    }

    bool deQueue() {
        if (currsize == 0) {
            return false;  // Queue is empty.
        }
        ListNode* nextelem = head->next;
        delete head;
        head = nextelem;
        currsize--;
        if (currsize == 0) {
            tail = nullptr;
            movinghead = nullptr;
        }
        return true;
    }

    int Front() {
        if (currsize == 0)
            return -1;
        else
            return head->val;
    }

    int Rear() {
        if (currsize == 0)
            return -1;
        else
            return tail->val;
    }

    bool isEmpty() {
        return currsize == 0;
    }

    bool isFull() {
        return currsize == size;
    }
};