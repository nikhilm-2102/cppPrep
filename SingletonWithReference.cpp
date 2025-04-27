#include <iostream>

class Singleton {
private:
    // Private constructor to prevent instantiation from outside
    Singleton() {
        std::cout << "Singleton instance created.\n";
    }

    // Delete the copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method to access the instance
    static Singleton& getInstance() {
        static Singleton instance; // The static instance is created on the first call
        return instance; // Return the reference to the singleton instance
    }

    // Example method to demonstrate the functionality
    void showMessage() {
        std::cout << "Hello from the Singleton class!\n";
    }
};

int main() {
    // Get the singleton instance and call a method
    Singleton& singleton = Singleton::getInstance();
    singleton.showMessage();

    return 0;
}
