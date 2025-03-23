#include<iostream>
using namespace std;

template <typename T>
class u_nik_ptr
{
    T* m_ptr;
    public:
    u_nik_ptr()
    {
       m_ptr = nullptr; 
    }
    u_nik_ptr(T* ptr)
    {
       m_ptr = ptr; 
    }
    
    u_nik_ptr(const u_nik_ptr& ref) = delete;
    u_nik_ptr& operator=(u_nik_ptr& ref) = delete;
    
    u_nik_ptr(u_nik_ptr&& rref)
    {
       m_ptr = rref.m_ptr;
       rref.m_ptr = nullptr;
    }
    
    u_nik_ptr& operator=(u_nik_ptr&& rref)
    {
        if(this == &rref) return *this;
        
        delete m_ptr;
        
        m_ptr = rref.m_ptr;
        rref.m_ptr = nullptr;
        return *this;
    }
    
    T* operator->() const 
    {
        return m_ptr;
    }

    T& operator*() const 
    {
        return *m_ptr;
    }
    
    ~u_nik_ptr()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
};

int main()
{
    u_nik_ptr<int> ptr1(new int(1));
    u_nik_ptr<int> ptr2 = std::move(ptr1);
    u_nik_ptr<int> ptr3(new int(2));
    u_nik_ptr<int> ptr4;
    ptr4 = std::move(ptr3);
    return 0;
}
