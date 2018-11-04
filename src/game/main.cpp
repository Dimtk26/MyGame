#include <BearLibTerminal.h>
#include <game/PlayerMovementSystem.h>
#include <game/Tile.h>
#include <game/WallSystem.h>
#include <vector>

int main() {
  terminal_open();
  terminal_refresh();

  int score = 5;
  auto player_tile = new Tile(1, 1, '@', "green");
  auto wall_tile = new Tile(5, 5, '#', "blue");

////////////////////-----------СОЗДАНИЕ КАРТЫ-----------////////////////////
  std::vector<Tile *> tiles;
  tiles.push_back(player_tile);
  tiles.push_back(wall_tile);
  wall_tile->horizontalWall(tiles,3,6,2);
  wall_tile->verticalWall(tiles,3,7,3);




    for(int i = 0; i < 5; i++){
        auto wall_tile2 = new Tile(i, 5, '#', "blue");
        tiles.push_back(wall_tile2);
    }
////////////////////------------------------------------////////////////////


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
        terminal_printf(10, 10, "[color=amber]Hello, people!");
        terminal_printf(11, 11, "[color=amber]Your score:%d",score);
    }
    terminal_refresh();
    // обновлять логику игры
  }

  terminal_close();
  delete player_movement_system;
  delete wall_system;
  delete player_tile;
  delete wall_tile;
}

