#include <iostream>

using namespace std;

int INITIAL_SIZE = 5;
class Stack {
    public:
        Stack();
       ~Stack();

        int size() const;
        bool pop(int &data);
        bool push(int data);

        void print() const;
    private:
        int* array_;
        int total_space_;
        int used_space_;
};

Stack::Stack(): array_(new int[INITIAL_SIZE]), total_space_(INITIAL_SIZE), used_space_(0) {

}

Stack::~Stack() {
    delete [] array_;
}

int Stack::size() const {
    return used_space_;
}

bool Stack::pop(int &data) {
    data = array_[used_space_ - 1];
    if (used_space_ == 0){
        return false;
    }
    --used_space_;
    return true;
}

bool Stack::push(int data) {
    if (used_space_ == total_space_){
        int* new_array_ptr = new int[2 * total_space_];
        int index = 0;
        while (index < total_space_){
            new_array_ptr[index] = array_[index];
            ++index;
        }
        delete[] array_;

        array_ = new_array_ptr;
        total_space_ = 2 * total_space_;
    }
    array_[used_space_] = data;
    ++ used_space_;
    return true;
}

void Stack::print() const {
    cout << "[";
    int index = 0;
    while (index < used_space_){
        cout << array_[index] << " ";
        ++ index;
    }
    cout << "]";
}

int main() {
    Stack stack;
    int value;
    for (int i = 0; i < 10; ++i){
        stack.push(i);
        stack.push(5 * i);
        if (stack.pop(value)){
            cout << value << " ";
        }
    }
    stack.print();
}
