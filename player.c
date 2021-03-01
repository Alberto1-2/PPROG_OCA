/** 
 * @resumen 
 * 
 * @file player.c
 * @author Alberto
 * @version 1.0 
 * @date 16-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "player.h"

/***Definition of structures, private data types and private variables***/
struct _Player{
   Id id;
   char name[WORD_SIZE +1];
   Id player_location;
   BOOL object;

};   
 /**Declaration of public functions***/
 Player *player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->object = FALSE;

  return newPlayer;
}

STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

Id player_get_id(Player* player){
  if (!player){
  	return NO_ID;
  }
  return player->id;
}

STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}
STATUS player_set_player_location(Player* player, Id id) {
    
  if (id == NO_ID) {
    return ERROR;
  }

  player->player_location = id;

	return OK;
}
Id player_get_player_location(Player* player) {
  return player->player_location;
}

STATUS player_set_object(Player* player, BOOL value) {
  if (!player) {
    return ERROR;
  }
  player->object = value;
  return OK;
}

BOOL player_get_object(Player* player) {
  if (!player) {
    return FALSE;
  }
  return player->object;
}

STATUS player_print(Player* player) {

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  return OK;
}

