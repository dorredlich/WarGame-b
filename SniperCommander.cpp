#include "SniperCommander.hpp"

using namespace std;

 Soldier* SniperCommander::findSoldier(vector<vector<Soldier*>> &board, pair<int,int> source){
        if (source.first>=0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()){
            Soldier* soldier = board[source.first][source.second];
            if (soldier == nullptr )
                return nullptr;
            if(soldier->numberOfPlayer != this->numberOfPlayer)
                return soldier;
        }
        return nullptr;
    }

    pair<Soldier*,pair<int,int>> SniperCommander::findTheStrongest(vector<vector<Soldier*>> &board){
        Soldier* soldierEnemy = nullptr; 
        pair<int,int> location = {0,0};
        int maxHealth = 0;
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[0].size();j++){
                Soldier* soldierEnemy2 = findSoldier(board,{i,j});
                if (soldierEnemy2 != nullptr && soldierEnemy2->numberOfPlayer != this->numberOfPlayer && soldierEnemy2->health_points > maxHealth){
                    maxHealth = soldierEnemy2->health_points;
                    soldierEnemy = soldierEnemy2;
                    location = {i,j};
                }          
            }
        }
        return {soldierEnemy,location};
    }

    void SniperCommander::allSniperShoot(vector<vector<Soldier*>> &board){
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j<board[0].size();j++){
                Soldier* soldier = board[i][j];
                if (soldier != nullptr && soldier->numberOfPlayer == this->numberOfPlayer && soldier->type == this->type){ // strongest enemy
                        soldier->activity({i,j}, board);
                }
                
            }
        }
    }

    void SniperCommander::activity(pair<int,int> source,vector<vector<Soldier*>> &board){
        pair<Soldier*,pair<int,int>> target = findTheStrongest(board);
        Soldier* soldierEnemy = target.first;
        pair<int,int> location = target.second;
        if (target.first != nullptr){
            soldierEnemy->health_points = soldierEnemy->health_points - this->per_activity;
            if (target.first->health_points <= 0){
                board[location.first][location.second] = nullptr;
            }
            
        }
        allSniperShoot(board);
        
    }