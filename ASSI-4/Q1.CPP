#include <iostream>

class MyClass {
public:
    int value;

    // Constructor to initialize the object
    MyClass(int val) {
        this->value = val; // Using 'this' pointer to distinguish the member variable from the parameter
        std::cout << "Object created with value: " << this->value << std::endl;
    }

    // A member function to display the value
    void displayValue() {
        std::cout << "The value is: " << this->value << std::endl;
    }
};

int main() {
    // Part (a): Pointer to an object
    // Create an object
    MyClass obj(50);

    // Create a pointer to the object
    MyClass* ptrObj;
    ptrObj = &obj;

    // Access members using the arrow (->) operator
    std::cout << "\nUsing a pointer to an object with the arrow (->) operator:" << std::endl;
    ptrObj->displayValue();
    std::cout << "Value accessed directly: " << ptrObj->value << std::endl;

    // Access members using the dot (.) operator (after dereferencing)
    std::cout << "\nUsing a pointer to an object with the dot (.) operator (after dereferencing):" << std::endl;
    (*ptrObj).displayValue();
    std::cout << "Value accessed directly: " << (*ptrObj).value << std::endl;

    // Part (b): The 'this' pointer
    // The 'this' pointer is demonstrated in the class's constructor and displayValue() function.
    // When MyClass obj(50); is called, the 'this' pointer inside the constructor
    // points to the memory address of the 'obj' object.
    
    return 0;
}