#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node * lchild;
    Node * rchild;
    explicit Node(int data = NULL) : data(data) {
        lchild = nullptr;
        rchild = nullptr;
    }

    void preOrder() {
        cout << data << " ";
        if (lchild) {
            lchild -> preOrder();
        }
        if (rchild) {
            rchild -> preOrder();
        }
    }
    void inOrder() {
        if (lchild) {
            lchild -> inOrder();
        }
        cout << data << " ";
        if (rchild) {
            rchild -> inOrder();
        }
    }
    void postOrder() {
        if (lchild) {
            lchild -> postOrder();
        }
        if (rchild) {
            rchild -> postOrder();
        }
        cout << data << " ";
    }
};

class BiTree {
private:
    Node * root;
public:
    BiTree() {
        root = nullptr;
    }

    ~BiTree() {
        delete root;
    }

    void build_demo() {
        root = new Node(1);
        root -> lchild = new Node(2);
        root -> lchild -> lchild = new Node(4);
        root -> lchild -> rchild = new Node(5);
        root -> rchild = new Node(3);
        root -> rchild -> lchild = new Node(6);
        root -> rchild -> rchild = new Node(7);
        root -> rchild -> lchild -> lchild = new Node(8);
        root -> rchild -> lchild -> rchild = new Node(9);
    }

    void preOrder() {
        root -> preOrder();
        cout << endl;
    }

    void inOrder() {
        root -> inOrder();
        cout << endl;
    }

    void postOrder() {
        root -> postOrder();
        cout << endl;
    }

    void levelOrder() {
        queue<Node*> my_queue;
        auto cur_node = new Node();
        my_queue.push(root);
        while(!my_queue.empty()) {
            cur_node = my_queue.front();
            my_queue.pop();
            cout << cur_node -> data << " " ;
            if (cur_node -> lchild) {
                my_queue.push(cur_node -> lchild);
            }
            if (cur_node -> rchild) {
                my_queue.push(cur_node -> rchild);
            }
        }
    }
};

int main() {
    BiTree biTree;
    biTree.build_demo();
    biTree.preOrder();
    biTree.inOrder();
    biTree.postOrder();
    biTree.levelOrder();

    return 0;
}