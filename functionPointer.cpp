#include <iostream>

// Regular function
void foo(int x) {
    std::cout << "Function foo called with " << x << std::endl;
}

int main() {
    void (*funcPtr)(int);  // Declare function pointer
    funcPtr = foo;         // Assign function address

    funcPtr(10);  // Call function using function pointer

    return 0;
}
