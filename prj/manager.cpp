#include "manager.h"
#include<iostream>
#include<ctime>
using namespace std;

Manager::Manager(QObject *parent) : QObject(parent)
{
    my_farm.set_type(0);

    theShop.reset_shop();
}

int Manager::get_seeds_price(QString name)
{
    return theShop.get_seeds_price(name.toStdString());
}

int Manager::get_tools_price(QString name)
{
    return theShop.get_tools_price(name.toStdString());
}

int Manager::getWaterTime()
{
    return my_farm.get_water_time();
}

int Manager::getCropTime()
{
    return my_farm.get_crop_time();
}

int Manager::get_crop_spoiled()
{
    return my_farm.get_spoiled_crop_time();
}
int Manager::get_water_spoiled()
{
    return my_farm.get_spoiled_water_time();
}

bool Manager::checkWaterTime()
{
    return my_farm.check_water_time();
}

bool Manager::checkCropTime()
{
    return my_farm.check_crop_time();
}

int Manager::water_timer()
{
    cerr << my_farm.get_water_timer() << endl;
    return my_farm.get_water_timer();
}

int Manager::crop_timer()
{
    return my_farm.get_crop_timer();
}

int Manager::spoiled_water_timer()
{
    return my_farm.get_spoiled_water_timer();
}

int Manager::spoiled_crop_timer()
{
    return my_farm.get_spoiled_crop_timer();
}

void Manager::plantSeed(int type)
{
    try
    {
       my_farm.set_type(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::plowFarm()
{
    try
    {
       my_farm.set_type(6);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::cropProduct()
{
    try
    {
       my_farm.set_type(0);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::spoiled_product()
{
    try
    {
       my_farm.set_type(0);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::waterVeg()
{
    my_farm.water();
}



int Manager::get_farm_type()
{
    return my_farm.get_type();
}
