//
// Created by on 19/10/2018.
//

#ifndef GAME_PLAYERMOVEMENTSYSTEM_H
#define GAME_PLAYERMOVEMENTSYSTEM_H


#include <game/System.h>
#include <game/Tile.h>



class PlayerMovementSystem : public System {
  Tile *const player;

 public:
  explicit PlayerMovementSystem(Tile *player);
  void update() override;
  bool isWalkableU();
  bool isWalkableD();
  bool isWalkableL();
  bool isWalkableR();
  void inRiverWalk();

  ~PlayerMovementSystem() override = default;
};

#endif  // GAME_PLAYERMOVEMENTSYSTEM_H
