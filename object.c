#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

struct _Object {
	Id id;
	char name[WORD_SIZE];
};

Object *object_create(Id id){
	
	Object *newObject = NULL;
	
	if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0'; //'\0' es el carácter de fin de cadena

  return newObject;
}

STATUS object_destroy(Object* object){
  if (!object) {	//!object es lo mismo que object == 0
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

Id object_get_id(const Object* object){
  if (!object){
  	return NO_ID;
  }
  return object->id;
}

STATUS object_set_name(Object* object, char* name){
	if (!object || !name){
		return ERROR;
	}
	if (!(strcpy(object->name, name))){
		return ERROR;
	}
	return OK;
}

const char* object_get_name(const Object* object){
	if (!object){
		return NULL;
		}
	return object->name;
}

STATUS object_print(const Object* object){
	if (!object){
		return ERROR;
		}
		
	fprintf(stdout, "--> Object (Id : %ld; Name: %s)\n", object->id, object->name);
	
	return OK;
}
