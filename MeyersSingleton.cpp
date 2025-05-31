class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; // Local static variable
        return instance;
    }

    // Delete copy and move semantics
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

private:
    Singleton() { /* Constructor logic */ }
    ~Singleton() = default;
};

/*
⚙️ How It Works
1. Static Local Variable:
static Singleton instance; is created on first call to getInstance().

It is destroyed automatically when the program exits.

C++11 and later guarantees thread-safe initialization of local statics.

2. Deleted Copy and Move:
Prevents multiple instances by deleting copy constructor and assignment operators.

3. Private Constructor:
Ensures that the class can't be instantiated from outside.*/
