// #abstract class -- binding within one certain scope.
#ifndef _PIZZAINTERFACE_H
#define _PIZZAINTERFACE_H
#include <bits/stdc++.h>
// namespace pizza
// {
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

        void Prepare();

        void Bake();

        void Cut();

        virtual void Box();
    };
//}

#endif //_PIZZAINTERFACE_H