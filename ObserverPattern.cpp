#include <iostream>
#include <vector>
#include <memory>

// Observer Interface
class Observer {
public:
    virtual void update(int newValue) = 0;
    virtual ~Observer() {}
};

// Subject (the one being observed)
class Subject {
    int value = 0;
    std::vector<Observer*> observers;

public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }

    void setValue(int newValue) {
        value = newValue;
        notify();
    }

private:
    void notify() {
        for (auto obs : observers) {
            obs->update(value);
        }
    }
};

// Concrete Observer A
class DisplayObserver : public Observer {
public:
    void update(int newValue) override {
        std::cout << "Display updated: value is " << newValue << "\n";
    }
};

// Concrete Observer B
class LoggerObserver : public Observer {
public:
    void update(int newValue) override {
        std::cout << "Logger: value changed to " << newValue << "\n";
    }
};

// Usage
int main() {
    Subject subject;
    DisplayObserver display;
    LoggerObserver logger;

    subject.attach(&display);
    subject.attach(&logger);

    subject.setValue(10);
    subject.setValue(42);
}
