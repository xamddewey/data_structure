#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node * next;
    explicit Node(int data = NULL) : data(data) {
        next = nullptr;
    }
};

class LinkedList {
private:
    Node * head;
public:
    LinkedList() : head(nullptr) {};

    bool insert(const int &loc, const int &val) {
        if (!head || loc < 1) return false;
        int sum = 0;
        for (auto node = head; node; node = node -> next){
            ++ sum;
        }
        if (loc > sum) return false;
        if (loc == 1) {
            auto node = new Node(val);
            node -> next = head;
            head = node;
            return true;
        }

        auto cur_node = head;
        int i = 1;
        while (cur_node -> next && i < loc - 1) {
            cur_node = cur_node -> next;
            ++i;
        }
        auto node = new Node(val);
        node -> next = cur_node -> next;
        cur_node -> next = node;
        return true;
    }

    void append(const int &val) {
        auto node = new Node(val);
        if (empty()) {
            head = node;
            return;
        }
        auto cur_node = head;
        while(cur_node -> next) {
            cur_node = cur_node -> next;
        }
        cur_node -> next = node;
    }

    bool empty() {
        return !head;
    }

    bool remove(const int &loc) {
        if (!head) return false;
        int sum = 0;
        for (auto node = head; node; node = node -> next) ++ sum;
        if (loc < 1 || loc > sum) return false;
        if (loc == 1) {
            head = head -> next;
            return true;
        }
        int i = 1;
        auto cur_node = head;
        while (cur_node -> next && i < loc - 1) {
            cur_node = cur_node -> next;
            ++ i;
        }
        auto delete_node = cur_node -> next;
        cur_node -> next = delete_node -> next;
        delete delete_node;
        return true;
    }

    void output() {
        for (auto node = head; node; node = node -> next) {
            cout << node -> data << " -> ";
        }
        cout << "nullptr" << endl;
    }

};

int main() {
    LinkedList linkedList;
    for (int i = 1; i < 7; ++i) {
        linkedList.append(i);
    }
    linkedList.output();
    linkedList.insert(2, 0);
    linkedList.output();
    linkedList.remove(2);
    linkedList.output();
    linkedList.remove(1);
    linkedList.output();
    linkedList.remove(5);
    linkedList.output();

    return 0;
}