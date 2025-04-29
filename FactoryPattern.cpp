#include <iostream>
#include <string>
using namespace std;

class Animal
{
    public:
        virtual void Speak() = 0;
        virtual ~Animal() {}
};

class Dog : public Animal
{
    public:
        void Speak() override
        {
            cout << "Woof\n";
        }
        
        ~Dog(){}
};

class Cat : public Animal
{
    public:
        void Speak() override
        {
            cout << "Meow\n";
        }
        
        ~Cat(){}
};

class AnimalFactory
{
  public:
    static Animal* GetAnimal(string strAnimal)
    {
        if("Dog" == strAnimal)
        {
            return new Dog();
        }
        
        if("Cat" == strAnimal)
        {
            return new Cat();
        }
        
        return nullptr;
    }
};

int main() {
    
    Animal* dog = AnimalFactory::GetAnimal("Dog");
    if(dog)
    {
        dog->Speak();
        delete dog;
        dog = nullptr;
    }
        
    Animal* cat = AnimalFactory::GetAnimal("Cat");
    if(cat)
    {
        cat->Speak();
        delete cat;
        cat = nullptr;
    }
    
    return 0;
}
