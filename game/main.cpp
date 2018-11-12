#include <BearLibTerminal.h>
#include <game/PlayerMovementSystem.h>
#include <game/Tile.h>
#include <game/Score.h>
#include <game/WallSystem.h>
#include <vector>

int main() {
  terminal_open();
  terminal_refresh();

  auto *score = new Score(0);
  auto player_tile = new Tile(1, 1, '@', "green");
  auto wall_tile = new Tile(5, 5, '#', "blue");
 auto coin_tile = new Tile(3,2,'$',"turquoise");
    //terminal_set("0x5E: $");


    // terminal_set("0x5E: C:\\Users\\umdim\\CLionProjects\\MyGame\\src\\6.png,bbox=4x4,size=16x16");



////////////////////-----------СОЗДАНИЕ КАРТЫ-----------////////////////////
  std::vector<Tile *> tiles;
  tiles.push_back(player_tile);
  tiles.push_back(wall_tile);
  tiles.push_back(coin_tile);

  wall_tile->horizontalWall(tiles,3,6,2);
  wall_tile->verticalWall(tiles,3,7,3);
  wall_tile->verticalWall(tiles,3,19,6);
  wall_tile->horizontalRiver(tiles,12,7,8);
  wall_tile->horizontalRiver(tiles,12,8,9);





    for(int i = 0; i < 5; i++){
        auto wall_tile2 = new Tile(i, 5, '#', "blue");
        tiles.push_back(wall_tile2);
    }
////////////////////------------------------------------////////////////////
   //C:\Users\umdim\CLionProjects\MyGame\src\6.png



  auto wall_system = new WallSystem(wall_tile);
  auto player_movement_system = new PlayerMovementSystem(player_tile);

  // Ждем, пока пользователь не закроет окно
  while (true) {
    if (terminal_has_input()) {
      player_movement_system->update();
      wall_system->update();

      if (terminal_read() == TK_CLOSE) break;
    }

    terminal_clear();

    for (auto tile : tiles) {
      terminal_color(color_from_name(tile->color));
      terminal_put(tile->x, tile->y, tile->symbol);

      score->addScore(tiles,player_tile);                     // добаление очков за сбор монет
      player_movement_system->inRiverWalk();                  //сносит течением воды

        terminal_put(3, 3, 0x5E);
       // terminal_put(3,2,'$');
        terminal_printf(16, 16, "[color=amber]Hello, people!");
        terminal_printf(17, 17, "[color=amber]Your score: %d.",*score);
    }
    terminal_refresh();
    // обновлять логику игры
  }

  terminal_close();
  delete player_movement_system;
  delete wall_system;
  delete player_tile;
  delete wall_tile;
  delete score;
}

