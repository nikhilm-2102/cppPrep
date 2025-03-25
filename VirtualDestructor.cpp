#include <iostream>

class base
{
public:
    base() 
    {
        std::cout << "Base class constructor\n";
    }
    
    virtual ~base() 
    {
        std::cout << "Base class destructor\n";
    }
};

class derived : public base
{
    int* m_arr;
    public:
    derived() 
    {
        std::cout << "derived class constructor\n";
        m_arr = new int[5];
    }
    
    ~derived() 
    {
        std::cout << "derived class destructor\n";
        delete[] m_arr;
    }
};

int main() {
    base* bptr = new derived();
    delete bptr;
    return 0;
}

/* Output - without virtual destructor - 
Base class constructor
derived class constructor
Base class destructor
*/

/* Output - with virtual destructor - 
Base class constructor
derived class constructor
derived class destructor
Base class destructor
*/
