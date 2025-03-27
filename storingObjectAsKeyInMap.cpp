
#include <iostream>
#include <map>

using namespace std;

class student
{
  int rollNo;
  public:
  
  student(int rNo) : rollNo(rNo){}
  
  bool operator<(const student& s) const
  {
      return rollNo < s.rollNo;
  }
  
  int getRollNo() { return rollNo;}
  
};

int main() {
    
    map<student,int> studMap;    
    
    studMap[student(5)] = 1;
    studMap[student(3)] = 2;
    studMap[student(1)] = 3;
    studMap[student(2)] = 4;
    
    for(auto& iter : studMap)
    {
        student s = iter.first;
        
        cout << s.getRollNo() << " " << iter.second << endl;
    }
    
    return 0;
}
