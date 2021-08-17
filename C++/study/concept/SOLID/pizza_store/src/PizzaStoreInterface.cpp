#include "../lib/PizzaStoreInterface.h"

Type convertType(const std::string &type)
{
    if (type == "cheese")
        return Type::CHEESE;
    else if (type == "greek")
        return Type::GREEK;
    else if (type == "pepperoni")
        return Type::PEPPERONI;
    else
        return Type::DEFAULT;
}

void PizzaStore::orderPizza(std::string type)
{
    Pizza *pizza;

    // -------------Make it "O" in SOLID---------------
    // ------------------------------------------------
    // switch (convertType(type))
    // {
    // case CHEESE:
    //     pizza = new CheesePizza();
    //     break;
    // case GREEK:
    //     pizza = new GreekPizza();
    //     break;
    // case PEPPERONI:
    //     pizza = new PepperoniPizza();
    //     break;
    // default:
    //     std::cout << "You have not chosen the pizza yet!" << std::endl;
    //     break;
    // }

    pizza = CreatePizza(type);
    if (pizza != nullptr)
    {
        pizza->Prepare();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();
    }
}