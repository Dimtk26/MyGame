//
// Created by on 19/10/2018.
//

#ifndef GAME_WALLSYSTEM_H
#define GAME_WALLSYSTEM_H

#include <game/System.h>
#include <game/Tile.h>

class WallSystem : public System {
  Tile *const wall;
  int state = 0;

 public:
  explicit WallSystem(Tile *wall);
  void update() override;
  ~WallSystem() override = default;
};

#endif  // GAME_WALLSYSTEM_H
