#pragma once

#include "Soldier.hpp"
#include <map>
#include <unordered_map>
#include <sstream>
#include <string> 


class FootCommander: public Soldier {
public:
    FootCommander(int t) : Soldier(150,20,t,1){}
   Soldier* findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source,std::map<std::string,int> &m);
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) override;
    void fullLife() override{
        this->health_points = 150;
    }
    
    
            
    
};
