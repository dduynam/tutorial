#include <bits/stdc++.h>

class Pizza
{
protected:
    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> topping;

public:
    Pizza(std::string _name, std::string _dough, std::string _sauce, std::vector<std::string> _topping)
        : name(_name),
          dough(_dough),
          sauce(_sauce),
          topping(_topping) {}

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

    void Box()
    {
        std::cout << "Boxing " << name << std::endl;
    }
};

class PizzaStore
{
public:
    void orderPizza()
    {
        Pizza *pizza = new Pizza("Pizza 1", "Thin dough", "Chilli sauce", {"Black Olives", "Onions"});
        pizza->Prepare();
        pizza->Bake();
        pizza->Cut();
        pizza->Box();
    }
};

int main()
{
    PizzaStore *store = new PizzaStore();
    store->orderPizza();
    return 0;
}