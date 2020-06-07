
#include "Board.hpp"
#include <iostream>
#include "Soldier.hpp"

using namespace std;

namespace WarGame {
    Soldier*& Board:: operator[](pair<int,int> location){
        return this->board[location.first][location.second];
    }
  Soldier* WarGame::Board::operator[](pair<int,int> location) const{
    return this->board[location.first][location.second];
}

    void Board::takeAction(pair<int,int> source, Soldier* soldier){
        soldier->activity(source, board);

    }

    void Board::findPlaceToMove(pair<int,int> source){
        int rows = source.first;
        int cols = source.second;
        if(rows >= board.size() || cols >= board[0].size() ||rows < 0 || cols < 0)
          throw invalid_argument("out Of Bound");
        Soldier* temp = this->board[rows][cols];
        if (temp == nullptr)
            return;
        throw invalid_argument("place is taken");
    }

    void Board:: move(uint player_number, pair<int,int> source, MoveDIR direction){
        int rows = source.first;
        int cols = source.second;
        if (rows >= board.size() || rows < 0 || cols >= board[rows].size() || cols < 0)
            throw invalid_argument("out of range");   
        Soldier* soldier = this->board[rows][cols];

        if (soldier == nullptr)
            throw invalid_argument("nobody in this place");
        if(soldier != nullptr && soldier->numberOfPlayer == player_number){
            if(direction == Up){
                this->findPlaceToMove({rows+1,cols});
                board[rows][cols] = nullptr;
                takeAction({rows+1,cols}, soldier);
                board[rows+1][cols] = soldier;
            }
            if(direction == Down){
                this->findPlaceToMove({rows-1,cols});
                board[rows][cols] = nullptr;
                takeAction({rows-1,cols}, soldier);
                board[rows-1][cols] = soldier;
            }
            if(direction == Right){
                this->findPlaceToMove({rows,cols+1});
                board[rows][cols] = nullptr;
                takeAction({rows,cols+1}, soldier);
                board[rows][cols+1] = soldier;
            }
            if(direction == Left){
                this->findPlaceToMove({rows,cols-1});
                board[rows][cols] = nullptr;
                takeAction({rows,cols-1}, soldier);
                board[rows][cols-1] = soldier;
            }
        }
        else{throw invalid_argument("place is for someone else");}
        
    }
    bool Board::has_soldiers(uint player_number) const{
        for(vector<Soldier*> v:board){
            for(Soldier* soldier:v){
                if ((soldier != nullptr) && soldier->numberOfPlayer == player_number)
                    return true;       
            }
        }
        return false;
    }


};
