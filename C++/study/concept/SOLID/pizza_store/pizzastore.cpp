#include <bits/stdc++.h>

// #abstract class -- binding within one certain scope.
class Pizza
{
protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> topping;

public:
    Pizza(std::string _name = "", std::string _dough = "", std::string _sauce = "", std::vector<std::string> _topping = {""})
        : name(_name),
          dough(_dough),
          sauce(_sauce),
          topping(_topping) {}

    virtual void makeAnAbstractionObject() = 0; // make this class become abstraction class.

    void Prepare()
    {

        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: ";
        std::for_each(topping.begin(), topping.end(), [&](std::string i)
                      { std::cout << i << ", "; });
        std::cout << std::endl;
    }

    void Bake()
    {
        std::cout << "Baking " << name << " in 30 mins" << std::endl;
    }

    void Cut()
    {
        std::cout << "Cutting " << name << std::endl;
    }

    virtual void Box()
    {
        std::cout << "Boxing " << name << std::endl;
    }
};

class CheesePizza : public Pizza
{
public:
    CheesePizza()
    {
        name = "The best cheese pizza";
        dough = "Very thin dough";
        sauce = "Very spicy sauce";
        topping.push_back("Black olives");
        topping.push_back("More Cheese");
    }

    void makeAnAbstractionObject() {}
};

class GreekPizza : public Pizza
{
public:
    GreekPizza()
    {
        name = "The moderate pizza";
        dough = "Thin dough";
        sauce = "Chilli sauce";
        topping.push_back("Tomato");
        topping.push_back("Seafood");
    }
    void makeAnAbstractionObject() {}
    void Box() override{
        std::cout << "Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
    }
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        name = "The best pepperoni pizza";
        dough = "Thick dough";
        sauce = "Sweet sauce";
        topping.push_back("Tomato");
    }
    void makeAnAbstractionObject() {}
};

enum Type
{
    CHEESE,
    GREEK,
    PEPPERONI,
    DEFAULT
};

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

class PizzaStore
{
public:
    void orderPizza(std::string type)
    {
        Pizza *pizza;

        switch (convertType(type))
        {
        case CHEESE:
            pizza = new CheesePizza();
            break;
        case GREEK:
            pizza = new GreekPizza();
            break;
        case PEPPERONI:
            pizza = new PepperoniPizza();
            break;
        default:
            std::cout << "You have not chosen the pizza yet!" << std::endl;
            break;
        }

        if (!pizza){
            pizza->Prepare();
            pizza->Bake();
            pizza->Cut();
            pizza->Box();
        }
    }
};

int main()
{
    PizzaStore *store = new PizzaStore();
    std::cout << "Choose a pizza that you want: ";
    std::string yourChoice;
    std::cin >> yourChoice;
    store->orderPizza(yourChoice);
    return 0;
}