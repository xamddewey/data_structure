#include <iostream>
using namespace std;
class Stack {
private:
    int * data;
    int max_size;
    int top;
public:
    explicit Stack(int max_size):max_size(max_size) {
        top = -1;
        data = new int[max_size];
    }

    bool push(int value) {
        if (!this -> isFull()) {
            ++top;
            data[top] = value;
            return true;
        }
        return false;
    }

    int getTop() {
        return data[top];
    }

    bool pop() {
        if (!this -> isEmpty()) {
            top--;
            return true;
        }
        return false;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max_size - 1;
    }
};

int main() {

    cout << "Hello, World!" << endl;
    return 0;
}