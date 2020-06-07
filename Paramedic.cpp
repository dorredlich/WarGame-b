#include "Paramedic.hpp"

Soldier* Paramedic::findSoldier(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source){
        if (source.first>=0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()){
            Soldier* soldier = board[source.first][source.second];
            if (soldier == nullptr )
                return nullptr;
            if(soldier->numberOfPlayer == this->numberOfPlayer)
                return soldier;
        }
        return nullptr;
        
    }


    void Paramedic::activity(std::pair<int,int> source, std::vector<std::vector<Soldier*>> &board){
        int soldier_locX  = source.first;
        int soldier_locY = source.second;
        int startSoldierX = soldier_locX - 1, endSoldierX = soldier_locX + 1 ,startSoldierY = soldier_locY - 1,endSoldierY = soldier_locY + 1;
        for(int i = startSoldierX; i <= endSoldierX; i++){
            for(int k = startSoldierY ; k <= endSoldierY; k++){
                if (!(i == soldier_locX && k == soldier_locY)){
                    Soldier* soldier = findSoldier(board,{i,k});
                    if(soldier != nullptr)
                        soldier->fullLife();
            }
        }
    }
}