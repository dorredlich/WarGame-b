#include "ParamedicCommander.hpp"

using namespace std;

  Soldier* ParamedicCommander::findSoldier(vector<vector<Soldier*>> &board, pair<int,int> source){
        if (source.first>=0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()){
            Soldier* soldier = board[source.first][source.second];
            if (soldier == nullptr )
                return nullptr;
            if(soldier->numberOfPlayer == this->numberOfPlayer)
                return soldier;
        }
        return nullptr;
        
    }

    void ParamedicCommander::findTeamMate(vector<vector<Soldier*>> &board, pair<int,int> source){
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                Soldier* soldier = board[i][j];
                if(soldier != nullptr && soldier->numberOfPlayer == this->numberOfPlayer && soldier->type == this->type){
                    soldier->activity({i,j}, board);
                }
            }
        }
    }

    void ParamedicCommander::activity(pair<int,int> source, vector<vector<Soldier*>> &board) {
       int soldier_locX  = source.first;
        int soldier_locY = source.second;
        int startSoldierX = soldier_locX - 1, endSoldierX = soldier_locX + 1 ,startSoldierY = soldier_locY - 1,endSoldierY = soldier_locY + 1;
        for(int i = startSoldierX; i <= endSoldierX; i++){
            for(int k = startSoldierY ; k<= endSoldierY; k++){
                if (!(i == soldier_locX && k == soldier_locY)){
                    Soldier* soldier = findSoldier(board,{i,k});
                    if(soldier != nullptr){
                        soldier->fullLife();
                        if (soldier->type == this->type)
                           fullLife();
                    }
                }   
            }
        }
        findTeamMate(board,source);
    }