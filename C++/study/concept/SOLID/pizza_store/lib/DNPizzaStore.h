/* DNPizzaStore */

#ifndef _DNPIZZASTORE_H
#define _DNPIZZASTORE_H

#include "PizzaInterface.h"
#include "PizzaStoreInterface.h"

class DNCheesePizza : public Pizza
{
public:
    DNCheesePizza();

    void makeAnAbstractionObject();
};

class DNGreekPizza : public Pizza
{
public:
    DNGreekPizza();

    void makeAnAbstractionObject();
    
    void Box() override;
};

class DNPepperoniPizza : public Pizza
{
public:
    DNPepperoniPizza();

    void makeAnAbstractionObject();
};

class DNPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override;
};

#endif //_DNPIZZASTORE_H