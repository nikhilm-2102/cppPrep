// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

using namespace std;
class my_string
{
    char* m_str;
    int m_len;
    
    public:
    
    my_string():m_str(nullptr),m_len(0){}
    
    my_string(const char* pStr)
    {
        if(pStr)
        {
            m_len = strlen(pStr);
            m_str = new char[m_len + 1];
            strcpy(m_str, pStr);
        }
        else
        {
           m_str = nullptr;
           m_len = 0;
        }
    }
    
    my_string(const my_string& rStr)
    {
        cout << "Copy Constructor \n";
        if(rStr.m_str)
        {
            m_len = strlen(rStr.m_str);
            m_str = new char[m_len + 1];
            strcpy(m_str, rStr.m_str);
        }
    }
    
    my_string& operator=(const my_string& rStr)
    {
        cout << "Assignment Operator\n";
        if(this != &rStr)
        {
            delete[] m_str;
            m_len = strlen(rStr.m_str);
            m_str = new char[m_len + 1];
            strcpy(m_str, rStr.m_str);
        }
        
        return *this;
    }
    
    my_string(my_string&& rref)
    {
       m_str = rref.m_str;
       m_len = rref.m_len;
       
       rref.m_str = nullptr;
       rref.m_len = 0;
    }
    
    my_string& operator=(my_string&& rref)
    {
        if(this != &rref)
        {
            delete[] m_str;
            
            m_str = rref.m_str;
            m_len = rref.m_len;
       
           rref.m_str = nullptr;
           rref.m_len = 0;
        }
        return *this;
    }
    
    ~my_string()
    {
        delete[] m_str;
        m_len = 0;
    }
    
    int getLen() { return m_len; }
    
    friend ostream& operator<<(ostream& cout, my_string& rStr);
    friend my_string operator+(const my_string& str1, const my_string& str2);
};

ostream& operator<<(ostream& cout, my_string& rStr)
{
    cout << rStr.m_str;
    return cout;
}

my_string operator+(const my_string& str1, const my_string& str2)
{
    my_string myString;
    if(str1.m_str != nullptr && str2.m_str != nullptr)
    {
        int len = str1.m_len +  str2.m_len;
        char* newStr = new char[len + 1];
        strcpy(newStr,str1.m_str);
        strcat(newStr,str2.m_str);
        
        myString = newStr;
        delete[] newStr;
    }
    return myString;
}

my_string GetString(const char* pStr)
{
    return my_string(pStr); 
    // Compiler does run time optimization here but if it will not do then it calls copy constructor or assignment operator and does unnecessary memory allocation for temp object so to avoid this overload move copy and move assignement
}

int main() {
    
    my_string str1("Nikhil");
    cout << str1 << endl;
    
    my_string str2 = "Mohite";
    cout << str1 << " " << str2 << endl;
    
    my_string str3 = str1;
    cout << str3 << endl;
    
    str3 = str2;
    cout << str3 << endl;
    
    my_string str4 = GetString("Ram");
    cout << str4 << endl;
    
    my_string str5 = str4 + str4;
    cout << str5 << endl;
    return 0;
}
