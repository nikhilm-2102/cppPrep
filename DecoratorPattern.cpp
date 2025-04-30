/* Decorator pattern is used to provide dynamic behavior to the object without changing the class
 It wraps the original object and extends its functionality at runtime. 
 
Where you should use it:
When you want to add features to individual objects, not the whole class.

When subclassing is not practical or leads to too many subclasses.

Examples:

UI components: Scrollbar + border + shadow on a window.

Logging: Add file logging, then console logging, then network logging—all without changing the core logic.

Text formatting: PlainText → Bold → Italic → Underline */


#include <iostream>
#include <string>

// Base Component
class Message {
public:
    virtual std::string getText() = 0;
    virtual ~Message() {}
};

// Concrete Component
class SimpleMessage : public Message {
public:
    std::string getText() override {
        return "Hello";
    }
};

// Base Decorator
class MessageDecorator : public Message {
protected:
    Message* wrappedMessage;
public:
    MessageDecorator(Message* msg) : wrappedMessage(msg) {}
};

// Concrete Decorator 1: Encryption
class EncryptedMessage : public MessageDecorator {
public:
    EncryptedMessage(Message* msg) : MessageDecorator(msg) {}
    
    std::string getText() override {
        return "[Encrypted] " + wrappedMessage->getText();
    }
};

// Concrete Decorator 2: Compression
class CompressedMessage : public MessageDecorator {
public:
    CompressedMessage(Message* msg) : MessageDecorator(msg) {}
    
    std::string getText() override {
        return "[Compressed] " + wrappedMessage->getText();
    }
};

// Usage
int main() {
    // Create base message
    SimpleMessage simple;
    
    // Decorate with encryption
    EncryptedMessage encrypted(&simple);
    
    // Further decorate with compression
    CompressedMessage compressed(&encrypted);
    
    std::cout << "Final Message: " << compressed.getText() << std::endl;

    return 0;
}
