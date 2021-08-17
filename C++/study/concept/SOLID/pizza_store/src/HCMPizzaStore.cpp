#include "../lib/HCMPizzaStore.h"

HCMCheesePizza::HCMCheesePizza()
{
    name = "HCM The best cheese pizza";
    dough = "HCM Very thin dough";
    sauce = "HCM Very spicy sauce";
    topping.push_back("Black olives");
    topping.push_back("More Cheese");
}

void HCMCheesePizza::makeAnAbstractionObject() {}

HCMGreekPizza::HCMGreekPizza()
{
    name = "HCM The moderate pizza";
    dough = "HCM Thin dough";
    sauce = "HCM Chilli sauce";
    topping.push_back("Tomato");
    topping.push_back("Seafood");
}
void HCMGreekPizza::makeAnAbstractionObject() {}
void HCMGreekPizza::Box()
{
    std::cout << "HCM Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
}

HCMPepperoniPizza::HCMPepperoniPizza()
{
    name = "HCM The best pepperoni pizza";
    dough = "HCM Thick dough";
    sauce = "HCM Sweet sauce";
    topping.push_back("Tomato");
}
void HCMPepperoniPizza::makeAnAbstractionObject() {}

Pizza *HCMPizzaStore::CreatePizza(std::string type)
{
    switch (convertType(type))
    {
    case CHEESE:
        return new HCMCheesePizza();
    case GREEK:
        return new HCMGreekPizza();
    case PEPPERONI:
        return new HCMPepperoniPizza();
    default:
        std::cout << "You have not chosen the pizza yet!" << std::endl;
        return nullptr;
    }
}
