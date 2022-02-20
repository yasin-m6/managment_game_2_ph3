#ifndef FARMER_H
#define FARMER_H

#include<vector>
#include<string>
#include"vegtebale.h"


class Farmer
{
public:
    Farmer();

    void plow();//
    void plant(std::string);
    void crop();//

    void sell_product(std::string);//
    void buy_seed(std::string);


    int get_seed_number(std::string);
    int get_product_number(std::string);
private:
    std::string farmers_name;
    int coin;

    std::vector<std::string> product;
    std::vector<int> product_number;

    std::vector<std::string> seed;
    std::vector<int> seed_number;

    int get_seed_address(std::string);
    int get_product_address(std::string);
};

#endif // FARMER_H
