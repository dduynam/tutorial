#include "../lib/PizzaInterface.h"
// namespace pizza
// {
    void Pizza::Prepare()
    {

        std::cout << "Preparing " << name << std::endl;
        std::cout << "Tossing dough..." << std::endl;
        std::cout << "Adding sauce..." << std::endl;
        std::cout << "Adding toppings: ";
        std::for_each(topping.begin(), topping.end(), [&](std::string i)
                      { std::cout << i << ", "; });
        std::cout << std::endl;
    }

    void Pizza::Bake()
    {
        std::cout << "Baking " << name << " in 30 mins" << std::endl;
    }

    void Pizza::Cut()
    {
        std::cout << "Cutting " << name << std::endl;
    }

    void Pizza::Box()
    {
        std::cout << "Boxing " << name << std::endl;
    }
//}
