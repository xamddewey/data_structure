#include <iostream>
using namespace std;

template <typename Type>
class Vector {
private:
    Type * data;
    int size, length;
public:
    explicit Vector(int size) : size(size) {
        length = 0;
        data = new Type[size];
    }

    ~Vector() {
        delete[] data;
    }

    bool insert(int loc, const Type & value) {
        cout << "loc is " << loc << endl;
        if (loc < 0 || loc > length) {
            cout << "no!" << endl;
            return false;
        }
        if (length >= size) {
            expand();
        }
        for (int i = length; i > loc; i--) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length ++;
        return true;
    }

    bool remove(int loc) {
        if (loc < 0 || loc >= length) {
            return false;
        }
        for (int i = loc + 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length --;
        return true;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
    }

    void expand() {
        Type * old_data = data;
        size *= 2;
        data = new Type[size];
        for (int i = 0; i < length; ++i) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }

    Type at(const int & loc) {
        if (loc < 0 || loc >= length) {
            return data[-length];
        }
        return data[loc];
    }
};

int main() {
    Vector<int> my_vec(10);
    for (int i = 0; i < 10; ++i) {
        my_vec.insert(i, i);
    }
    my_vec.print();
    int n = 5;
    while (n > 0) {
        int operate_num;
        cin >> operate_num;
        switch (operate_num) {
            case 1: {
                int location, value;
                cin >> location >> value;
                if (my_vec.insert(location, value)) {
                    cout << "insert successfully!" << endl;
                } else {
                    cout << "insert failed!" << endl;
                }
                break;
            }
            case 2: {
                int location;
                cin >> location;
                if (my_vec.remove(location)) {
                    cout << "remove successfully!" << endl;
                } else {
                    cout << "remove failed!" << endl;
                }
                break;
            }
            case 3: {
                int location;
                cin >> location;
                cout << my_vec.at(location) << endl;
            }
            default:
                break;
        }
        my_vec.print();
        n--;
    }

    return 0;
}
