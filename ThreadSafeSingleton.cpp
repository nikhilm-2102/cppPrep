#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class singleton
{
    static singleton* instance;
    static mutex mtx;ā
    singleton() {}
    
    public:
    singleton(const singleton& s) = delete;
    singleton& operator=(const singleton& s) = delete;
    singleton(singleton&& rref) = delete;
    singleton& operator=(singleton&& rref) = delete;
    
    static singleton* GetInstance()
    {
        if(instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr)
            {
                cout << "Instance created\n";
                instance = new singleton();
            }
        }
        return instance;
    }
};

singleton* singleton::instance = nullptr;
mutex singleton::mtx;

void ThreadOne()
{
    singleton* instance = singleton::GetInstance();
    if(instance)
    {
        cout << "Therad one got the instance\n";
    }
}

void ThreadTwo()
{
    singleton* instance = singleton::GetInstance();
    if(instance)
    {
        cout << "Therad two got the instance\n";
    }
}

void ThreadThree()
{
    singleton* instance = singleton::GetInstance();
    if(instance)
    {
        cout << "Therad three got the instance\n";
    }
}

int main() {
    
    thread t1(ThreadOne);
    thread t2(ThreadTwo);
    thread t3(ThreadThree);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
