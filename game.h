/** 
 * @brief It defines the game interface
 * for each command
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"

typedef struct _Game{
  Player* player;
  Object* object;
  Space* spaces[MAX_SPACES + 1];
  T_Command last_cmd;
} Game;

STATUS game_add_space(Game* game, Space* space);
STATUS game_create(Game* game);
STATUS game_create_from_file(Game* game, char* filename);
STATUS game_update(Game* game, T_Command cmd);
STATUS game_destroy(Game* game);
BOOL   game_is_over(Game* game);
void   game_print_data(Game* game);
Space* game_get_space(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game);
T_Command game_get_last_command(Game* game);
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Space* space, Id id); //Devuele la dirección del primer objeto que encuentra (ya que en este programa solo va a haber uno).

#endif
