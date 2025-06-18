#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool isEvensTurn = true;

int arr[] = {1,2,3,4,5,6,7,8,9,10};


void PrintEvens()
{
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    unique_lock<mutex> lock(mtx);
    for(int i = 0; i < arrSize; i++)
    {
        cv.wait(lock, []() {return isEvensTurn;});
        if(arr[i] % 2 == 0)
        {
            cout << " Even - "<< arr[i] << endl;
        }
        
        isEvensTurn = false;
        cv.notify_one();
    }
}

void PrintOdds()
{
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    unique_lock<mutex> lock(mtx);
    for(int i = 0; i < arrSize; i++)
    {
        cv.wait(lock, [] {return !isEvensTurn;});
        if(arr[i] % 2 != 0)
        {
            cout << " Odd - "<< arr[i] << endl;
        }
        
        isEvensTurn = true;
        cv.notify_one();
    }
}

int main() {
    thread evenThread(PrintEvens);
    thread oddThread(PrintOdds);
    evenThread.join();
    oddThread.join();
    return 0;
}
