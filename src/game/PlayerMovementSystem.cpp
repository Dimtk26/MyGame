//
// Created by on 19/10/2018.
//

#include <BearLibTerminal.h>
#include <game/PlayerMovementSystem.h>

void PlayerMovementSystem::update() {
  int key = terminal_peek();

  if (key == TK_UP && isWalkableU()) { player->y--;}
  if (key == TK_DOWN && isWalkableD()) { player->y++;}
  if (key == TK_LEFT && isWalkableL()) { player->x--; }
  if (key == TK_RIGHT && isWalkableR()) { player->x++;}
    }

PlayerMovementSystem::PlayerMovementSystem(Tile *const player) : player(player) {}

bool PlayerMovementSystem::isWalkableU() {
    if(player->y-1<0){ return false;}
    return terminal_pick(player->x, player->y-1, 0) != '#';
}
bool PlayerMovementSystem::isWalkableD() {
    return terminal_pick(player->x, player->y+1, 0) != '#';
}
bool PlayerMovementSystem::isWalkableL() {
    if(player->x-1<0){ return false;}
    return terminal_pick(player->x-1, player->y, 0) != '#';
}
bool PlayerMovementSystem::isWalkableR() {
    return terminal_pick(player->x+1, player->y, 0) != '#';
}

