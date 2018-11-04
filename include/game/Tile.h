//
// Created by on 19/10/2018.
//
#include <vector>
#ifndef GAME_TILE_H
#define GAME_TILE_H

class Tile {
 public:
  int x;
  int y;
  int symbol;
  const char *color;

  Tile(int x, int y, int symbol, const char *color);
    std::vector<Tile *> horizontalWall(std::vector<Tile *> &tiles,int size, int x, int y);
    std::vector<Tile *> verticalWall(std::vector<Tile *> &tiles,int size, int x, int y);
};

#endif  // GAME_TILE_H
