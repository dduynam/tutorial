/* HaNoiPizzaStore */

#ifndef _HanoiPIZZASTORE_H
#define _HanoiPIZZASTORE_H

#include "PizzaInterface.h"
#include "PizzaStoreInterface.h"

class HanoiCheesePizza : public Pizza
{
public:
    HanoiCheesePizza();

    void makeAnAbstractionObject();
};

class HanoiGreekPizza : public Pizza
{
public:
    HanoiGreekPizza();

    void makeAnAbstractionObject();
    
    void Box() override;
};

class HanoiPepperoniPizza : public Pizza
{
public:
    HanoiPepperoniPizza();

    void makeAnAbstractionObject();
};

class HanoiPizzaStore : public PizzaStore
{
    Pizza *CreatePizza(std::string type) override;
};

#endif //_HanoiPIZZASTORE_H