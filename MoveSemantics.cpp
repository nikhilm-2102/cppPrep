#include <iostream>

class buffer
{
    int size;
    int* data;
    public:
    buffer(int nSize)
    {
        size = nSize;
        data = new int[size];
    }
    
    buffer(const buffer& rBuffer)
    {
        size = rBuffer.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = rBuffer.data[i];
    }
    
    buffer& operator=(const buffer& rBuffer)
    {
        if(this != &rBuffer)
        {
            delete[] data;
            size = rBuffer.size;
            data = new int[size];
            for (int i = 0; i < size; ++i)
                data[i] = rBuffer.data[i];
        }
        return *this;
    }
    
    buffer(buffer&& rref)
    {
        std::cout << "move constructor\n";
        data = rref.data;
        size = rref.size;
        rref.data = nullptr;
        rref.size = 0;
    }
    
    buffer& operator=(buffer&& rref)
    {
        std::cout << "move assignment\n";
        if(this != &rref)
        {
            delete[] data;
            data = rref.data;
            size = rref.size;
            rref.data = nullptr;
            rref.size = 0;
        }
        return *this;
    }
    
    ~buffer()
    {
        delete[] data;
        size = 0;
    }
    
};

buffer GetBuffer(int size)
{
    return buffer(size);
}

int main() {
    buffer b = GetBuffer(9); // Compiler does the return value optimization here so we will not see call to a move constructor from here 
    buffer b = std::move(GetBuffer(9));
    return 0;
}
