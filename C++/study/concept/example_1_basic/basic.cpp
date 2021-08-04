#include <iostream>
#include <string>
#include <random>
#include <unistd.h>
struct Human
{
    Human(std::string _name, int _age, float _height, float _weight)
    {
        name = _name;
        age = _age;
        height = _height;
        weight = _weight;
    }
    Human(const Human &man)
    {
        name = man.name;
        age = man.age;
        height = man.height;
        weight = man.weight;
        std::cout << " Copy constructor is called!!!" << std::endl;
    }
    std::string name;
    int age;
    float height;
    float weight;
};

std::string BMI_index(Human &man)
{
    float bmi = man.weight / (man.height * man.height);
    std::string result;
    if (bmi < 18)
        result = "skinnn";
    else if (bmi > 25)
        result = "overweight";
    else
        result = "normal";

    return result;
    //std::cout << "BMI Index of " << man.name << " is " << result << std::endl;
}

void predictFuture(Human &_man, int time)
{
    for (int i = 0; i < time; i++)
    {
        _man.weight += 2;
    }
    std::cout << _man.name << " after " << time << ((time < 2) ? " year" : " years") << " will be " << BMI_index(_man) << std::endl;
}

int main()
{

    Human CFW4[5] = {
        Human("Nam", 23, 1.72, 70),
        Human("Tin", 24, 1.8, 72),
        Human("Kiet", 25, 1.8, 75),
        Human("Quynh", 26, 1.8, 60),
        Human("Hanh", 27, 1.72, 50)};

    Human *people = nullptr;
    people = CFW4;
    int size = sizeof(CFW4) / sizeof(CFW4[0]);

    for (int i = 0; i < size; i++)
    {
        std::cout << "Name: " << (people + i)->name << ", Age: " << people[i].age << ", Height: " << people[i].height << ", Weight: " << people[i].weight << std::endl;
    }

    while (1)
    {
        //predictFuture(Vnmese, rand() % 10);
        sleep(5);
    }
    return 0;
}