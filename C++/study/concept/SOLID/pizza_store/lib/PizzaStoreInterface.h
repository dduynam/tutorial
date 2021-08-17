#ifndef _PIZZASTOREINTERFACE_H
#define _PIZZASTOREINTERFACE_H
#include <bits/stdc++.h>
#include "PizzaInterface.h"

enum Type
{
    CHEESE,
    GREEK,
    PEPPERONI,
    DEFAULT
};

Type convertType(const std::string &type);

class PizzaStore
{
public:
    void orderPizza(std::string type);
protected:
    virtual Pizza *CreatePizza(std::string type) = 0;
};

#endif //_PIZZASTOREINTERFACE_H