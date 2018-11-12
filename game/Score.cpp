//
// Created by umdim on 06.11.2018.
//

#include <game/Score.h>
#include <game/Tile.h>
#include <game/PlayerMovementSystem.h>


Score::Score(int score) : score(score){}

void Score::addScore(std::vector<Tile *> &tiles,Tile *const player) {
   if(terminal_pick(player->x, player->y, 0) == '$'){
       terminal_set("0x5E: none");

        int x = player->x;
       int y = player->y;
       terminal_put(x, y, ' ');
      // terminal_print(x, y,"s");
       //auto afterScore = new Tile(x, y, '#', "blue");
      // tiles.push_back(afterScore);
       score++;

   }

}










