#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

class Soldier{
public:
    int health_points;
    int per_activity;
    int numberOfPlayer;
    int type;
    Soldier(int HP, int PA,int num, int t): health_points(HP), per_activity(PA),numberOfPlayer(num), type(t) {}
    virtual void activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board) = 0;
    virtual void fullLife() = 0 ;
    virtual ~Soldier(){}
};


