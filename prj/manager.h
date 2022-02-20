#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "vegtebale.h"
#include "shop.h"
#include<QString>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private:
    Vegtebale my_farm;
    Shop theShop;

signals:

public slots:

    int get_seeds_price(QString);
    int get_tools_price(QString);

    int getWaterTime();
    int getCropTime();

    int get_crop_spoiled();
    int get_water_spoiled();

    bool checkWaterTime();
    bool checkCropTime();



    int water_timer();
    int crop_timer();
    int spoiled_water_timer();
    int spoiled_crop_timer();

    void plantSeed(int);
    void plowFarm();
    void cropProduct();
    void spoiled_product();
    void waterVeg();

    int get_farm_type();

};

#endif // MANAGER_H
