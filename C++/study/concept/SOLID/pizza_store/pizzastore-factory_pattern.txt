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
    void Box() override
    {
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

protected:
    virtual Pizza *CreatePizza(std::string type) = 0;
};

/* DNPizzaStore */
class DNCheesePizza : public Pizza
{
public:
    DNCheesePizza()
    {
        name = "DN The best cheese pizza";
        dough = "DN Very thin dough";
        sauce = "DN Very spicy sauce";
        topping.push_back("Black olives");
        topping.push_back("More Cheese");
    }

    void makeAnAbstractionObject() {}
};

class DNGreekPizza : public Pizza
{
public:
    DNGreekPizza()
    {
        name = "DN The moderate pizza";
        dough = "DN Thin dough";
        sauce = "DN Chilli sauce";
        topping.push_back("Tomato");
        topping.push_back("Seafood");
    }
    void makeAnAbstractionObject() {}
    void Box() override
    {
        std::cout << "DN Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
    }
};

class DNPepperoniPizza : public Pizza
{
public:
    DNPepperoniPizza()
    {
        name = "DN The best pepperoni pizza";
        dough = "DN Thick dough";
        sauce = "DN Sweet sauce";
        topping.push_back("Tomato");
    }
    void makeAnAbstractionObject() {}
};

class DNPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override
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
};

/* HCMPizzaStore */
class HCMCheesePizza : public Pizza
{
public:
    HCMCheesePizza()
    {
        name = "HCM The best cheese pizza";
        dough = "HCM Very thin dough";
        sauce = "HCM Very spicy sauce";
        topping.push_back("Black olives");
        topping.push_back("More Cheese");
    }

    void makeAnAbstractionObject() {}
};

class HCMGreekPizza : public Pizza
{
public:
    HCMGreekPizza()
    {
        name = "HCM The moderate pizza";
        dough = "HCM Thin dough";
        sauce = "HCM Chilli sauce";
        topping.push_back("Tomato");
        topping.push_back("Seafood");
    }
    void makeAnAbstractionObject() {}
    void Box() override
    {
        std::cout << "HCM Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
    }
};

class HCMPepperoniPizza : public Pizza
{
public:
    HCMPepperoniPizza()
    {
        name = "HCM The best pepperoni pizza";
        dough = "HCM Thick dough";
        sauce = "HCM Sweet sauce";
        topping.push_back("Tomato");
    }
    void makeAnAbstractionObject() {}
};

class HCMPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override
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
};

/* HaNoiPizzaStore */
class HanoiCheesePizza : public Pizza
{
public:
    HanoiCheesePizza()
    {
        name = "Hanoi The best cheese pizza";
        dough = "Hanoi Very thin dough";
        sauce = "Hanoi Very spicy sauce";
        topping.push_back("Black olives");
        topping.push_back("More Cheese");
    }

    void makeAnAbstractionObject() {}
};

class HanoiGreekPizza : public Pizza
{
public:
    HanoiGreekPizza()
    {
        name = "Hanoi The moderate pizza";
        dough = "Hanoi Thin dough";
        sauce = "Hanoi Chilli sauce";
        topping.push_back("Tomato");
        topping.push_back("Seafood");
    }
    void makeAnAbstractionObject() {}
    void Box() override
    {
        std::cout << "Hanoi Boxing...And luckily You will get one pizza addtionally since we are in promotional period" << std::endl;
    }
};

class HanoiPepperoniPizza : public Pizza
{
public:
    HanoiPepperoniPizza()
    {
        name = "Hanoi The best pepperoni pizza";
        dough = "Hanoi Thick dough";
        sauce = "Hanoi Sweet sauce";
        topping.push_back("Tomato");
    }
    void makeAnAbstractionObject() {}
};

class HanoiPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override
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
};

int main()
{
    PizzaStore *dn_store = new DNPizzaStore();
    dn_store->orderPizza("cheese");
    std::cout << std::endl;
    PizzaStore *hcm_store = new HCMPizzaStore();
    hcm_store->orderPizza("cheese");
    std::cout << std::endl;
    PizzaStore *hanoi_store = new HanoiPizzaStore();
    hanoi_store->orderPizza("cheese");
    std::cout << std::endl;

    // // Enter random option
    // std::cout << "Choose a pizza that you want: ";
    // std::string yourChoice;
    // std::cin >> yourChoice;
    // store->orderPizza(yourChoice);

    return 0;
}