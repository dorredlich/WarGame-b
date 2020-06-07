#pragma once

#include "Soldier.hpp"
#include <iostream>



class FootSoldier: public Soldier {
public:
    FootSoldier(int t) : Soldier(100,10,t,1){}
    Soldier* findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) override;
    void fullLife() override{
        this->health_points = 100;
    }
    
            
    
};
