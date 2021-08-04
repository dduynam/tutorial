#include <iostream>
#include <string>

class Human /* Base Class */
{
public: //Access Modifier
    Human()
    {
    }

    /* pay attention to this one: const std::string &_variable */
    Human(const std::string &_name, int _age, bool _status = false /*default parameter*/) : name(_name), status(_status), age(_age) // Initialization List
    {
    }

    /* Copy constructor */
    Human(const Human &_man) : name(_man.name), status(_man.status), age(_man.age)
    {
    }

    ~Human()
    {
        std::cout << "Delete " << name << " Object" << std::endl;
    }

    void sleep()
    {
    }

    virtual std::string flirt(std::string saysomething)
    {
        return "I love you";
    }

    void findLover()
    {
        if (age > 18)
            status = true;
    }

    void showStatus()
    {
        std::cout << name << ": " << (status ? "In Relationship" : "Single") << std::endl;
    }

private: /* encapsulation */
    int age;
    bool status; // 0: single, 1: in relationship

protected: /* make sure property can be inherited, while declared as private can not be inherited */
    std::string name;
};

/* Existing method, constructor, desconstructor,... can not be inherited*/
class Young : public Human
{
public:
    Young(const std::string &_name, int _age, bool _status = false /*default parameter*/) : Human(_name, _age, _status) // Initialization List
    {
    }

    /* Copy constructor */
    Young(const Human &_man)
    {
    }

    ~Young()
    {
        std::cout << "Delete " << name << " Object" << std::endl;
    }

    std::string flirt(std::string saysomething)
    {
        return "I love you... Chut Chut";
    }
};

class Mature : public Human
{
public:
    Mature(const std::string &_name, int _age, bool _status = false /*default parameter*/) : Human(_name, _age, _status) // Initialization List
    {
    }

    /* Copy constructor */
    Mature(const Human &_man)
    {
    }

    ~Mature()
    {
        //std::cout << "Delete " << name << " Object" << std::endl;
    }

    void GetMarried()
    {
        std::cout << name << " "
                  << "settle down" << std::endl;
    }

    std::string flirt(std::string saysomething)
    {
        return "I really love you";
    }
};

/* Diamond Inheritance --> causing unexpected behaviour */
class GenZ : public Young, public Mature
{
};

/* Multilevel Inheritence */
class GenZ_1 : public Mature
{
};

int main()
{
    Human nam("Nam", 22);
    //pointer is always base class. it can not be derived)
    Human *woman = new Mature("HH", 18, 0);
    Human *man = new Young("Daniel", 18, 0);
    std::cout << man->flirt("saylove") << std::endl;
    std::cout << woman->flirt("saylove") << std::endl;
    
    /* call virtual function from base class */
    std::cout << woman->Human::flirt("saylove") << std::endl;

    // man->findLover();
    // man->showStatus();
    // man->GetMarried();
    delete man;
}