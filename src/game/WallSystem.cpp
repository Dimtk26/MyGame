//
// Created by on 19/10/2018.
//

#include <game/WallSystem.h>
#include "game/PlayerMovementSystem.h"

//#include <iimgctx.h>

void WallSystem::update() {
  if (state == 0) {
    state = 1;
    wall->color = "red";
  } else {
    state = 0;
    wall->color = "blue";
  }

}
WallSystem::WallSystem(Tile *const wall) : wall(wall) {}


