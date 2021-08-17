/* HCMPizzaStore */

#ifndef _HCMPIZZASTORE_H
#define _HCMPIZZASTORE_H

#include "PizzaInterface.h"
#include "PizzaStoreInterface.h"

class HCMCheesePizza : public Pizza
{
public:
    HCMCheesePizza();

    void makeAnAbstractionObject();
};

class HCMGreekPizza : public Pizza
{
public:
    HCMGreekPizza();

    void makeAnAbstractionObject();
    
    void Box() override;
};

class HCMPepperoniPizza : public Pizza
{
public:
    HCMPepperoniPizza();

    void makeAnAbstractionObject();
};

class HCMPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override;
};

#endif // _HCMPIZZASTORE_H
