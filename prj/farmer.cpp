#include "farmer.h"
#include<iostream>
#include<stdexcept>
using namespace std;

Farmer::Farmer()
{

}

void Farmer::plant(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return ;
    }

    if(address > -1)
    {
        if(seed_number[address] > 1)
        {
            seed_number[address]--;
        }
        else
        {
            seed.erase(seed.begin() + address);
            seed_number.erase(seed_number.begin() + address);
        }
    }
}

void Farmer::buy_seed(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return ;
    }


    if(address > -1)
    {
        seed_number[address]++;
    }
    else
    {
        seed.push_back(type);
        seed_number.push_back(1);
    }
}

int Farmer::get_seed_number(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return 0;
    }



    if(address > -1)
    {
        return seed_number[address];
    }
    else
    {
        return 0;
    }
}

int Farmer::get_product_number(string type)
{
    int address;

    try
    {
        address = get_product_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return 0;
    }



    if(address > -1)
    {
        return product_number[address];
    }
    else
    {
        return 0;
    }
}

int Farmer::get_seed_address(string type)
{
    if(type != "goje" && type != "kahoo" && type != "kalam" && type != "havij" && type != "gandom")
    {
        throw invalid_argument("seed type is wrong!!!!");
    }

    for(size_t i = 0 ; i < seed.size() ; i++)
    {
        if(seed[i] == type)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int Farmer::get_product_address(string type)
{
    if(type != "goje" && type != "kahoo" && type != "kalam" && type != "havij" && type != "gandom")
    {
        throw invalid_argument("product type is wrong!!!!");
    }

    for(size_t i = 0 ; i < product.size() ; i++)
    {
        if(product[i] == type)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}
