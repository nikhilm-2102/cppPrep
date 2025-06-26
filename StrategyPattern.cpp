// below code represents why and in which situation there is a need of strategy design pattern - 
#include <iostream>
using namespace std;

// Strategy design pattern - 
// This design pattern is useful when we need dynamic behavior at runtime
// Without strategy design pattern only by using inheritance we can achive same thing but
// it will need to create a seperate derived class every time

// Example withour strategy design pattern
// Consider we have different warriors and each have different attack strategy
// warriors can attack using sword / gun / fire etc..
// If we think to go ahead only with inheritance
class Warrior
{
  public:
  virtual void attack() = 0;
  virtual ~Warrior() {}
};

class SwordWarrior : public Warrior
{
  public:
    void attack() override
    {
        cout << "Attcking with sword..\n";
    }
    
    ~SwordWarrior(){}
};

class GunWarrior : public Warrior
{
  public:
    void attack() override
    {
        cout << "Attcking with gun..\n";
    }
    
    ~GunWarrior(){}
};

// now consider the scenario, we need to introduce new warrior which can attck using 
// sword and gun both ?

// In this situation with inheritance we need to introduce a new derived class

class SwordAndGunWarrior : public Warrior
{
  bool switchAttack;
  public:
    SwordAndGunWarrior() : switchAttack(false){}
    void attack() override
    {
        if(switchAttack)
        {
            cout << "Attcking with sword..\n";
        }
        else
        {
            cout << "Attcking with gun..\n";
        }
    }
    
    void changeWeapon()
    {
        switchAttack = !switchAttack;
    }
    
    ~SwordAndGunWarrior(){}
};

int main() {
   /* Warrior* swordWarrior = new SwordWarrior();
    swordWarrior->attack();
    
    Warrior* gunWarrior = new GunWarrior();
    gunWarrior->attack();*/
    
    Warrior* swordAndGunWarrior = new SwordAndGunWarrior();
    swordAndGunWarrior->attack();
    SwordAndGunWarrior* actualWarrior = dynamic_cast<SwordAndGunWarrior*>(swordAndGunWarrior);
    if(actualWarrior)
        actualWarrior->changeWeapon();
    swordAndGunWarrior->attack();
    
    /*delete swordWarrior;
    delete gunWarrior;*/
    delete swordAndGunWarrior;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/* As per the design in the above example we chosen to go with an inheritance but code become complicated and need of introduce a new derived class
in case of dymanic behavior */
/* Strategy design pattern helps to provide dynamic behavior by empower a class with an dynamic behavior object. This means the class has a member which choses the dynamic behavior*/

#include <iostream>
using namespace std;

class AttackStrategy
{
    public:
    virtual void attack() = 0;
    virtual ~AttackStrategy(){}
};

class SwardAttack : public AttackStrategy
{
    public:
    void attack() override
    {
         cout << "Attcking with sword..\n";
    }
    
    ~SwardAttack(){}
};

class GunAttack : public AttackStrategy
{
    public:
    void attack() override
    {
         cout << "Attcking with gun..\n";
    }
    
    ~GunAttack(){}
};

class Warrior
{
    AttackStrategy* m_ptrAttackStrategy;
    
  public: 
    Warrior(AttackStrategy* pAttackStrategy)
    {
        m_ptrAttackStrategy = pAttackStrategy;  
    }
    
    void Attack()
    {
        if(m_ptrAttackStrategy)
            m_ptrAttackStrategy->attack();
    }
    
    void changeWeapon(AttackStrategy* pAttackStrategy)
    {
        if(pAttackStrategy == nullptr || m_ptrAttackStrategy == pAttackStrategy)
            return;
            
        delete m_ptrAttackStrategy;
        
        m_ptrAttackStrategy = pAttackStrategy;
    }
    
    ~Warrior()
    {
        if(m_ptrAttackStrategy)
            delete m_ptrAttackStrategy;
            m_ptrAttackStrategy = nullptr;
    }
    
};

int main() {
    
    Warrior warrior(new SwardAttack());
    warrior.Attack();
    
    warrior.changeWeapon(new GunAttack());
    warrior.Attack();
    
    return 0;
}
