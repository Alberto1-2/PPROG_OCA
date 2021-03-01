/** 
 * @brief It defines a player
 * 
 * @file player.h
 * @author Alberto
 * @version 1.0 
 * @date 16-02-2021
 * @copyright GNU Public License
 */


#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"


/***Definition of public data types and structures ***/
typedef struct _Player Player;

/***Declaration of public functions***/
Player* player_create(Id id);
STATUS player_destroy(Player* player);

Id player_get_id(Player* player);
STATUS player_set_name(Player* space, char* name);
const char* player_get_name(Player* player);

STATUS player_set_player_location(Player* player, Id id);
Id player_get_player_location(Player* player);

STATUS player_set_object(Player* player, BOOL value);
Id player_get_object(Player* player);

STATUS player_print(Player* player);

#endif
