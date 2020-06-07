#include "FootCommander.hpp"

#include <map>
#include <unordered_map>
#include <sstream> 
#include <string>

using namespace std;

Soldier* FootCommander::findSoldier(vector<std::vector<Soldier*>> &board, pair<int,int> source,map<std::string,int> &m){
    if (source.first >= 0 && source.first < board.size() && source.second >= 0 && source.second < board[0].size()){
            Soldier* soldier = board[source.first][source.second];
            if (soldier == nullptr )
                return nullptr;
            if(soldier->numberOfPlayer != this->numberOfPlayer)
                return soldier;
            stringstream ss;
            ss << soldier;  
            string name = ss.str();
            if (soldier->numberOfPlayer == this->numberOfPlayer && soldier->type == this->type && m[name] == 0){
                m[name] = 1;
                soldier->activity(source, board);
            }
            
        }
        return nullptr;
}

void FootCommander::activity(pair<int,int> source, vector<vector<Soldier*>> &board) {
        int soldier_locX = source.first;
        int soldier_locY = source.second;
        int startSoldierX = soldier_locX - 1, endSoldierX = soldier_locX + 1 ,startSoldierY = soldier_locY - 1,endSoldierY = soldier_locY + 1;
        map<string,int> m;
        while (!(startSoldierX < 0 && endSoldierX > board.size() && startSoldierY < 0 && endSoldierY > board[0].size())){
            for(int i = startSoldierX; i <= endSoldierX; i++){
                for(int j = startSoldierY ; j<= endSoldierY; j++){
                    if (!(i == soldier_locX && j == soldier_locY)){
                        Soldier* soldier = findSoldier(board,{i,j},m);
                        if(soldier != nullptr){ 
                            soldier->health_points = soldier->health_points - this->per_activity;
                            if (soldier->health_points <= 0)
                                board[i][j] = nullptr;
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