#include "../lib/HanoiPizzaStore.h"

HanoiCheesePizza::HanoiCheesePizza()
{
    Pizza::name = "Hanoi The best cheese pizza";
    dough = "Hanoi Very thin dough";
    sauce = "Hanoi Very spicy sauce";
    topping.push_back("Black olives");
    topping.push_back("More Cheese");
}

void HanoiCheesePizza::makeAnAbstractionObject() {}

HanoiGreekPizza::HanoiGreekPizza()
{
    name = "Hanoi The moderate pizza";
    dough = "Hanoi Thin dough";
    sauce = "Hanoi Chilli sauce";
    topping.push_back("Tomato");
    topping.push_back("Seafood");
}
void HanoiGreekPizza::makeAnAbstractionObject() {}
void HanoiGreekPizza::Box()
{
    std::cout << "Hanoi Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
}

HanoiPepperoniPizza::HanoiPepperoniPizza()
{
    name = "Hanoi The best pepperoni pizza";
    dough = "Hanoi Thick dough";
    sauce = "Hanoi Sweet sauce";
    topping.push_back("Tomato");
}
void HanoiPepperoniPizza::makeAnAbstractionObject() {}

Pizza *HanoiPizzaStore::CreatePizza(std::string type) 
{
    switch (convertType(type))
    {
    case CHEESE:
        return new HanoiCheesePizza();
    case GREEK:
        return new HanoiGreekPizza();
    case PEPPERONI:
        return new HanoiPepperoniPizza();
    default:
        std::cout << "You have not chosen the pizza yet!" << std::endl;
        return nullptr;
    }
}
