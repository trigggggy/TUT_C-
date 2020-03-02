#include <iostream>

using namespace std;

// Stack is a name for a data structure where a new element is
// added in the front, but element removal also happens from the
// front. It is also called LIFO (Last In, First Out)
// in other words the element that was added to the last will
// be removed the first.
class Stack {
  public:
    Stack();
    ~Stack();

    // empty will only return true if there are no elements
    // in the stack ie the linked list is empty.
    bool empty () const;

    // push_front will insert the new_value on top of the stack
    // ie in front of the linked list.
    void push_front (int new_value);


    // pop_front will remove the topmost value from the stack
    // ie the first element of the linked list. The removed
    // value will be stored in removed_value and the return
    // will be true if the removal of an element is successful.
    // If not (ie the stack is empty), return value is false.
    bool pop_front (int & removed_value);

    // Print the elements stored in the stack on top to bottom
    // order. This method is mainly for testing purposes.
    void print () const;

  private:
    struct Element {
        int data;
        Element * next_ptr;
    };

    Element * first_ptr;
};

Stack::Stack(): first_ptr(nullptr) {
}

bool Stack::empty() const{
if(first_ptr==nullptr){
    return true;
}else{
    return false;
}
}


void Stack::push_front(int new_value){
    Element* new_ptr = new Element;
    Element* old_ptr = new Element;

    new_ptr->data = new_value;
    new_ptr->next_ptr = nullptr;

    if (first_ptr == nullptr){
        first_ptr=new_ptr;
        first_ptr->next_ptr=nullptr;
    }else{
        old_ptr = first_ptr;
        first_ptr=new_ptr;
        first_ptr->next_ptr=old_ptr;
    }
}

bool Stack::pop_front(int & removed_value){
if(first_ptr == nullptr){
    return false;
}else{
    removed_value = first_ptr->data;
    first_ptr = first_ptr->next_ptr;
    return true;
}


}

void Stack::print() const{

    Element* current_ptr = first_ptr;

   while ( current_ptr != nullptr ) {
        cout << current_ptr->data << endl;
       current_ptr = current_ptr->next_ptr;
    }


}

Stack::~Stack() {
    while ( first_ptr != nullptr ) {
        Element* delete_ptr = first_ptr;
        first_ptr = first_ptr->next_ptr;
        delete delete_ptr;
    }
}

int main()
{
    int b;
    Stack s;
    if(s.empty()){
        cout<<"asdfafafafafafafaf"<<endl;
    }
    s.push_front(10);
    s.push_front(17);
    s.push_front(17);
    if(s.empty()){
        cout<<"asdfafafafafafafaf"<<endl;
    }
    s.print();
    s.pop_front(b);
    s.print();
    cout << "Hello World!" << endl;
    return 0;
}
