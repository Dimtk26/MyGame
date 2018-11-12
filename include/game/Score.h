//
// Created by umdim on 06.11.2018.
//

#include <game/System.h>
#include <game/Tile.h>
#include <BearLibTerminal.h>
#include <game/PlayerMovementSystem.h>


#ifndef MYGAME_SCORE_H
#define MYGAME_SCORE_H

class Score{
public:
    int score;
    Score(int score);
    void addScore(std::vector<Tile *> &tiles,Tile *const player);

};
#endif //MYGAME_SCORE_H

