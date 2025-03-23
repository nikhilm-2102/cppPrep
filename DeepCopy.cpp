#include <iostream>

class Test
{
	int* ptr;
	public:
	Test(int v)
	{
		ptr = new int(v);
	}
	
	Test(const Test& ref)
	{
		ptr = new int();
		*ptr = *ref.ptr;
	}
	
	Test& operator=(const Test& ref)
	{
		if(this == &ref) 
			return *this;
		
		delete ptr;
		ptr = new int();
		*ptr = *ref.ptr;
		return *this;
	}
	
	~Test()
	{
		delete ptr;
	}
};

int main() {
    Test T1(1);
    Test T2 = T1;
    Test T3(5);
    T3 = T2; 

    return 0;
}
