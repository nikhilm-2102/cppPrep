/* Templates are used to provide generic functionality using which class or function can work with multiple data types in a type independent manner.
At compile time based on the argument you are passing, compiler creates a function / class for that type. We do not need to create multiple functions / classes for each data type*/

/* Template Specialization is useful when you want to provide special functionality for a particular data type*/ 

#include <iostream>

using namespace std;
template <typename T>
class Printer
{
    T data;
    public:
    Printer(T tData) : data(tData) {}
    void Print()
    {
        cout << data << endl;
    }
};

template <>
class Printer <int>
{
    int data; // “If I need to write a completely separate class for int, why not just write a normal class for int instead of bothering with templates?” See line #33
    public:
    Printer(int tData) : data(tData) {}
    void Print()
    {
        cout << data << endl;
    }
};

/*class Printer 
{
    int data;
    public:
    Printer(int tData) : data(tData) {}
    void Print()
    {
        cout << data << endl;
    }
};*/
// This gives error: class template 'Printer' redeclared as non-template

int main() {
    Printer<int> p(10);
    Printer<bool> p1(true);
    p.Print();
    p1.Print();
    
    return 0;
}
