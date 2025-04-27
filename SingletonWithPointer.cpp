#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
    static Singleton* instance;
    static mutex mtx;
    
    Singleton(){}
    
    public:
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton* GetInstance()
    {
        lock_guard<mutex> lock(mtx);
        
        if(instance == nullptr)
        {
          instance = new Singleton();  
        }
        
        return instance;
    }
    
    void foo()
    {
        cout << "Hello\n";
    }
    
    ~Singleton()
    {
        if (instance)
        {
           delete instance;
           instance = nullptr;
        }
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* instance = Singleton::GetInstance();
    instance->foo();
    
    Singleton* instance1 = Singleton::GetInstance();
    instance1->foo();

    return 0;
}
