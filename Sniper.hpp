#pragma once

#include "Soldier.hpp"


class Sniper: public Soldier {
public:
    Sniper(int t) : Soldier(100,50,t,2){}
    Soldier* findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
    std::pair<Soldier*,std::pair<int,int>> findTheStrongest(std::vector<std::vector<Soldier*>> &board);
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) override;
    void fullLife() override{
        this->health_points = 100;
    }
    
            
    
};

