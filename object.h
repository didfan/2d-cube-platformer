#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "vector.h"

typedef struct {
	Vector position;
	Vector size;
	float verticalSpeed;
	char symbol;
} Object;

void InitObject(Object* object, Vector position, Vector size, char symbol);

#endif