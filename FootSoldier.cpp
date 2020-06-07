#include "FootSoldier.hpp"

using namespace std;


  Soldier* FootSoldier::findSoldier(vector<std::vector<Soldier*>> &board, pair<int,int> source){
        if (source.first >= 0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()){
            Soldier* soldier = board[source.first][source.second];
            if (soldier == nullptr )
                return nullptr;
            if(soldier->numberOfPlayer != this->numberOfPlayer)
                return soldier;
        }
        return nullptr;
        
    }


    void FootSoldier::activity(pair<int,int> source, vector<vector<Soldier*>> &board){
     
        int soldier_locX  = source.first;
        int soldier_locY = source.second;
        int startSoldierX = soldier_locX - 1, endSoldierX = soldier_locX + 1 ,startSoldierY = soldier_locY - 1,endSoldierY = soldier_locY + 1;
        while (!(startSoldierX < 0 && endSoldierX > board.size() && startSoldierY < 0 && endSoldierY > board[0].size())){
            for(int i = startSoldierX; i <= endSoldierX; i++){
                for(int k = startSoldierY ; k <= endSoldierY; k++){
                    if (!(i == soldier_locX && k == soldier_locY)){
                        Soldier* soldier = findSoldier(board,{i,k});
                        if(soldier != nullptr){ 
                            soldier->health_points = soldier->health_points - this->per_activity;
                            if (soldier->health_points <= 0) 
                                board[i][k] = nullptr;
                            return; 
                        }
                    }   
                }
            }
            startSoldierX--;
            startSoldierY--;
            endSoldierX++;
            endSoldierY++;
        }
    }