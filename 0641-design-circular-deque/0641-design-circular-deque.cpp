struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = NULL, Node* prev = NULL)
        : val(val), next(next), prev(prev) {}
};

class MyCircularDeque {
public:
    Node* head;
    Node* rear;
    int size;
    int capacity;

    MyCircularDeque(int k) {
        head=NULL;
        rear=NULL;
        size=0;
        capacity=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(head==NULL) {
            head=new Node(value);
            rear=head;
        } else {
            Node* newHead=new Node(value);
            newHead->next=head;
            head->prev=newHead;
            head=newHead;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(head==NULL) {
            head=new Node(value);
            rear=head;
        } else {
            Node* newNode=new Node(value,NULL, rear);
            rear->next=newNode;
            rear=newNode;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(size==1) {
            head=NULL;
            rear=NULL;
        } else {
            Node* nextNode=head->next;
            delete head;
            head=nextNode;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (size == 1) {
            head = NULL;
            rear = NULL;
        } else {
            Node* prevNode = rear->prev;
            delete rear;
            rear = prevNode;
        }
        size--;
        return true; 
    }
    
    int getFront() {
        return (isEmpty()) ? -1 : head->val;
    }
    
    int getRear() {
        return (isEmpty()) ? -1 : rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */