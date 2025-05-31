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

// Its not good idea to delete instance in destructor as due to this there is a chance of double deletion because delete instace ; this will be recursive call to the destructor
// So instead of this add a memothod destoryInstance() to delete instance
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
