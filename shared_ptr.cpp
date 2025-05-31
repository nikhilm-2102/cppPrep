// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

template <typename T>
class shared_ptr
{
    T* m_pRawPtr;
    int* m_pRefCount;
    
    public:
    shared_ptr():m_pRawPtr(nullptr),
                m_pRefCount(nullptr)
    {}
    
    shared_ptr(T* ptr)
    {
       if(ptr)
       {
            m_pRawPtr = ptr;
            m_pRefCount = new int(1);
       }
    }
    
    shared_ptr(const shared_ptr& ref)
    {
        m_pRefCount = ref.m_pRefCount;
        m_pRawPtr = ref.m_pRawPtr;
        ++(*m_pRefCount);
    }
    
    shared_ptr& operator=(const shared_ptr& ref)
    {
        if(this == &ref)
            return *this;
        
        if(m_pRefCount &&  --(*m_pRefCount) == 0)
        {
            delete m_pRawPtr;
            delete m_pRefCount;
        }
        
        m_pRefCount = ref.m_pRefCount;
        m_pRawPtr = ref.m_pRawPtr;
        ++(*m_pRefCount);
        
        return *this;
    }
    
    ~shared_ptr()
    {
        if(m_pRefCount &&  --(*m_pRefCount) == 0)
        {
            delete m_pRawPtr;
            m_pRawPtr = nullptr;
            
            delete m_pRefCount;
            m_pRefCount = nullptr;
        }
    }
    
    int use_count()
    {
        if(m_pRefCount)
            return *m_pRefCount;
        
        return 0;
    }
    
    T* operator->()
    {
        return m_pRawPtr;
    }
    
    T& operator*()
    {
        return *m_pRawPtr;
    }
};


int main() {
    shared_ptr<int> sPtr1(new int(5));
    cout << "Use count = " << sPtr1.use_count() << endl;
    
    {
        shared_ptr<int> sPtr2 = sPtr1;
        cout << "Use count = " << sPtr2.use_count() << endl;
    }

    cout << "Use count = " << sPtr1.use_count() << endl;
    return 0;
}
