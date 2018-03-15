#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node * next = nullptr;

    explicit Node(int val = NULL) : val(val){}
};

// 此链式队列带头结点，这样才比较好处理
class LinkedQueue {
private:
    Node * head;
    Node * tail;
public:
    LinkedQueue() {
        head = new Node();
        tail = head;
    }

    bool push(const int& val) {
        auto new_node = new Node(val);
        tail -> next = new_node;
        tail = tail -> next;
        return true;
    }

    bool pop() {
        if (isEmpty()) return false;
        auto head_next = head -> next;
        if (tail == head_next) {
            tail = head;
            delete head_next;
            return true;
        }
        head -> next = head_next -> next;
        delete head_next;
        return true;
    }

    bool isEmpty() {
        return head == tail;
    }

    void output() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        auto current_node = head -> next;
        cout << "head node -> ";
        while (current_node != nullptr) {
            cout << current_node -> val << " -> ";
            current_node = current_node -> next;
        }
        cout << "NULL" << endl;
    }
};



int main() {
    LinkedQueue queue;
    for (int i = 0; i < 5; i++) {
        queue.push(i);
    }
    queue.output();
    queue.push(5);
    queue.output();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.output();
    return 0;
}