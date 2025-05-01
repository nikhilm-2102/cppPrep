#include <iostream>
#include <string>
#include <stack>

using namespace std;

void ReverseString(string& str, int start, int end)
{
    // Approach 1 - Using recursion
    /*if(start >= end)
        return;
        
    swap(str[start], str[end]);
    ReverseString(str, ++start, --end);*/
    
    
    // Approach 2 - Using reverse iteration
    /*string reversed = "";
    for(int i = end; i >= 0; i--)
    {
       reversed += str[i]; 
    }
    
    str = reversed;*/
    
    // Approach 3 - using iteration and swapping
    /*int len = str.length();
    for(int i = 0; i < len / 2; i++)
    {
        swap(str[i], str[len - 1 - i]);
    }*/
    
    // Approach 4 - Using stack
    stack<char> charStack;
    for(char ch : str)
    {
        charStack.push(ch);
    }
    
    string reversed = "";
    while(!charStack.empty())
    {
        char ch = charStack.top();
        reversed += ch;
        charStack.pop();
    }
    str = reversed;
}

int main() {
    string str = "Nikhil Mohite";
    ReverseString(str, 0, str.length() - 1);
    cout << str;
    return 0;
}
