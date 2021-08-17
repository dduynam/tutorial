#include <bits/stdc++.h>
#include "lib/PizzaStoreInterface.h"
#include "lib/DNPizzaStore.h"
#include "lib/HCMPizzaStore.h"
#include "lib/HanoiPizzaStore.h"

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