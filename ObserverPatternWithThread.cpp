#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>

using namespace std;

/*
The Observer pattern defines a one-to-many relationship 
so that when one object changes state, all its dependents are notified automatically.

Where you should use it:
When multiple objects need to react to a change in another object.

When you want to implement event handling or publish-subscribe systems.

Examples:

GUI: Buttons notifying listeners when clicked.

Stock market: Investors get updates when stock prices change.

Logging or notification system when state changes.

*/

// Multiple object needs to react when there is state change


class Investor
{
  public:
  virtual void GetUpdate(int LTP) = 0;
  virtual void Subscribe() = 0;
  virtual ~Investor() {}
};

static mutex mtx;
class StockBroadcaster
{
    static vector<Investor*> subscribersList;
  public:
      static void Subscribe(Investor* pInvestor)
      {
        if(pInvestor)
        {
            lock_guard<mutex> lock(mtx);
            subscribersList.push_back(pInvestor);
        }
      }
      
      static void Publish(int LTP)
      {
          lock_guard<mutex> lock(mtx);
          for(Investor* pInvestor : subscribersList)
          {
              pInvestor->GetUpdate(LTP);
          }
      }
      
      static void Unsubscribe(Investor* pInvestor) 
      {
          lock_guard<mutex> lock(mtx);
          subscribersList.erase(std::remove(subscribersList.begin(), subscribersList.end(), pInvestor), subscribersList.end());
      }
};

vector<Investor*> StockBroadcaster::subscribersList;


class InstitutionalInvestor : public Investor
{
  public:
  void GetUpdate(int LTP) override
  {
      cout << "InstitutionalInvestor - LTP : " << LTP << endl;
  }
  
  void Subscribe()
  {
      StockBroadcaster::Subscribe(this);
  }
  
  ~InstitutionalInvestor() {}
};

class RetailInvestor : public Investor
{
  public:
  void GetUpdate(int LTP) override
  {
      cout << "RetailInvestor - LTP : " << LTP << endl;
  }
  
  void Subscribe()
  {
      StockBroadcaster::Subscribe(this);
  }
  
  ~RetailInvestor() {}
};

void BroadcastThread()
{
    static int limit = 5;
    while(limit > 0)
    {
        std::srand(std::time(0));
        int randomNumber = (std::rand() % 100) + 1;
        StockBroadcaster::Publish(randomNumber);
        --limit;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    Investor* pInstInvestor = new InstitutionalInvestor();
    pInstInvestor->Subscribe();
    
    Investor* pRetailInvestor = new RetailInvestor();
    pRetailInvestor->Subscribe();
    
    thread broadcaster(BroadcastThread);
    broadcaster.join();
    
    StockBroadcaster::Unsubscribe(pInstInvestor);
    StockBroadcaster::Unsubscribe(pRetailInvestor);
    
    delete pInstInvestor;
    delete pRetailInvestor;
    return 0;
}
