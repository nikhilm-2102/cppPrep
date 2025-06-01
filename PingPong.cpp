#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

bool isPingsTurn = true;
mutex mtx;
condition_variable cv;

void Ping()
{
    for(int i = 0; i < 5; i++)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return isPingsTurn; });
        
        cout << "Ping ";
        
        isPingsTurn = false;
        cv.notify_all();
    }
}

void Pong()
{
    for(int i = 0; i < 5; i++)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]() {return !isPingsTurn; });
        
        cout << "Pong ";
        
        isPingsTurn = true;
        cv.notify_all();
    }
}

int main() {
    thread T1(Ping);
    thread T2(Pong);
    
    T1.join();
    T2.join();
    return 0;
}
