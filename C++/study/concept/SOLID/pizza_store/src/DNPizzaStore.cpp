#include "../lib/DNPizzaStore.h"

DNCheesePizza::DNCheesePizza()
{
    name = "DN The best cheese pizza";
    dough = "DN Very thin dough";
    sauce = "DN Very spicy sauce";
    topping.push_back("Black olives");
    topping.push_back("More Cheese");
}

void DNCheesePizza::makeAnAbstractionObject() {}

DNGreekPizza::DNGreekPizza()
{
    name = "DN The moderate pizza";
    dough = "DN Thin dough";
    sauce = "DN Chilli sauce";
    topping.push_back("Tomato");
    topping.push_back("Seafood");
}
void DNGreekPizza::makeAnAbstractionObject() {}

void DNGreekPizza::Box()
{
    std::cout << "DN Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
}

DNPepperoniPizza::DNPepperoniPizza()
{
    name = "DN The best pepperoni pizza";
    dough = "DN Thick dough";
    sauce = "DN Sweet sauce";
    topping.push_back("Tomato");
}

void DNPepperoniPizza::makeAnAbstractionObject() {}

Pizza *DNPizzaStore::CreatePizza(std::string type) 
{
    switch (convertType(type))
    {
    case CHEESE:
        return new DNCheesePizza();
    case GREEK:
        return new DNGreekPizza();
    case PEPPERONI:
        return new DNPepperoniPizza();
    default:
        std::cout << "You have not chosen the pizza yet!" << std::endl;
        return nullptr;
    }
}