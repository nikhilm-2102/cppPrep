#include <iostream>
#include <string>

// Base case
void print() {
    std::cout << "End of recursion" << std::endl;
}

// Recursive variadic function
template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << std::endl;
    print(args...);  // Recursive call
}

int main() {
    print(10,2.5,"Nik", 'c', true);
    
    return 0;
}
