#include "Shop.h"

Shop::Shop()
{

}

Shop::Shop(std::string name)
{
    this->name = name;
}

void Shop::Update(float price)
{
    this->price = price;

    //Lets print on console just to test the working
    std::cout << "Price at "<< name << " is now "<< price << "\n";
}
