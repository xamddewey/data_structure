#include <iostream>
using namespace std;
class Queue{
private:
    int * data;
    int max_size;
    int front;
    int rear;
    int num;
public:
    explicit Queue(int size) :max_size(size) {
        data = new int[max_size];
        front = 0;
        rear = -1;
        num = 0;
    }
    ~Queue() {
        delete[] data;
    }
    bool push(const int &value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % max_size;
        data[rear] = value;
        ++num;
        return true;
    }
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % max_size;
        --num;
        return true;
    }
    bool isEmpty() {
        return num == 0;
    }
    bool isFull() {
        return num == max_size;
    }
    void output() {
        if (isEmpty()) return;
        int i = front;
        do {
            cout << data[i] << " ";
            i = (i + 1) % max_size;
        } while(i != (rear + 1) % max_size);
        cout << endl;
    }
};


int main() {
    Queue queue(6);
    for (int i = 0; i < 6; i++) {
        queue.push(i);
    }
    queue.output();
    queue.pop();
    queue.output();
    queue.push(6);
    queue.output();
    queue.pop();
    queue.output();
    return 0;
}