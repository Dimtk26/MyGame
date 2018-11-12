//
// Created by  on 19/10/2018.
//

#include <vector>
#include <game/Tile.h>

Tile::Tile(int x, int y, int symbol, const char *const color) : x(x), y(y), symbol(symbol), color(color) {}

std::vector<Tile *> Tile::horizontalWall(std::vector<Tile *> &tiles,int size, int x, int y) {
        for(int i = x; i < size+x; i++){
        auto wall = new Tile(i, y, '#', "#C5AA6D");
        tiles.push_back(wall);
    }
    return tiles;
}
std::vector<Tile *> Tile::verticalWall(std::vector<Tile *> &tiles,int size, int x, int y) {
        for(int i = y; i < size+y; i++){
        auto wall = new Tile(x, i, '#', "#C5AA6D");
        tiles.push_back(wall);
    }
    return tiles;
}

std::vector<Tile *> Tile::horizontalRiver(std::vector<Tile *> &tiles, int size, int x, int y) {
    for(int i = x; i < size+x; i++){
        auto wall = new Tile(i, y, '~', "#4DE6F9");
        tiles.push_back(wall);
    }
    return tiles;
}
