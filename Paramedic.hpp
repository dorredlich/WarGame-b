#pragma once

#include "Soldier.hpp"
#include <iostream>


class Paramedic: public Soldier {
public:
    Paramedic(int t) : Soldier(100,50,t,3){}
    Soldier* findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) override;
    void fullLife() override{
        this->health_points = 100;
    }
    
};
