#pragma once

#include "Soldier.hpp"
#include <iostream>


class ParamedicCommander: public Soldier {
public:
    ParamedicCommander(int t) : Soldier(200,100,t,3){}
   Soldier* findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
    void findTeamMate(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source);
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) override;
    void fullLife() override{
        this->health_points = 200;
    }
    
            
    
};

