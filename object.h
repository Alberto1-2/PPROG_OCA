/** 
 * @brief It defines an object
 * 
 * @file object.h
 * @author Alvaro Bartolome
 * @version 1.0 
 * @date 15-02-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

Object* object_create(Id id);
STATUS object_destroy(Object* object);
Id object_get_id(const Object* object);
STATUS object_set_name(Object* object, char* name);
const char* object_get_name(const Object* object);
STATUS object_print(const Object* object);

#endif
