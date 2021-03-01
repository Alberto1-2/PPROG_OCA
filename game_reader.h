#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "types.h"

STATUS game_reader_load_spaces(Game* game, char* filename);
STATUS game_reader_create_from_file(Game* game, char* filename);

#endif
