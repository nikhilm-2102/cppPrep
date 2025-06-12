#include <iostream>
#include <vector>

using namespace std;

class Employee
{
    protected:
    int m_nSalary;
    public:
    Employee() : m_nSalary(0) {}
    Employee(int salary) : m_nSalary(salary) 
    {
        cout << "Employee Constructor\n";
    }
    
    virtual int GetSalary()
    {
        cout << "I am employee and I receive salary\n";        
        return m_nSalary;
    }
    
    virtual ~Employee()
    {
        cout << "Employee Destructor\n";
    }
};


class SalesPerson : public Employee
{
    int m_nCommission;
    public:
    SalesPerson() : m_nCommission(0) {}
    SalesPerson(int salary, int commission) : Employee(salary) 
    {
        cout << "SalesPerson Constructor\n";
        m_nCommission = commission;
    }
    
    int GetSalary() override 
    {
        cout << "I am SalesPerson and I receive salary + commisson\n";        
        return m_nSalary + m_nCommission;
    }
    
    int GetCommission()
    {
        return m_nCommission;
    }
    
    ~SalesPerson()
    {
        cout << "SalesPerson Destructor\n";
    }
};

// Upcasting - Converting derived class type to base class type is called as upcasting
// This is also known as static_cast or compile time cast
// Example - 
// Employee* emp = new Salesperson(100,5);
// Here converted derived class type to base class type 

// Downcasting / dynamic_cast / run time casting - 
// Converting derived class type into base class type
// Employee* emp = new Salesperson(100,5);
// SalesPerson* sp = dynamic_cast<SalesPerson*>(emp);

int GetTotalCommission(vector<Employee*> employees)
{
    int nTotalCommission = 0;
    for(Employee* emp : employees)
    {
        SalesPerson* sp = dynamic_cast<SalesPerson*>(emp);
        if(sp)
            nTotalCommission += sp->GetCommission(); 
    }
    return nTotalCommission;
}

int main() {
    Employee* emp1 = new SalesPerson(100,2);
    //emp1->GetSalary();
    //delete emp1;
    
    Employee* emp2 = new SalesPerson(100,4);
    
    Employee* emp3 = new Employee(500);
    
    Employee* emp4 = new Employee(5500);
    
    vector<Employee*> employees {emp1, emp2, emp3, emp4};
    int totalCommission = GetTotalCommission(employees);
    cout << "Total Commission is = " << totalCommission << endl;
    
    delete emp1;
    delete emp2;
    delete emp3;
    delete emp4;
    return 0;
}
