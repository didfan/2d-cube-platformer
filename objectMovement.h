#ifndef OBJECT_MOVEMENT_H_INCLUDED
#define OBJECT_MOVEMENT_H_INCLUDED

#include "vector.h"
#include "object.h"
#include "checkMapPositions.h"

void MoveHorizontal(char** map, Object* object, int directionX, float speed, int sizeMapY);
void VerticalMove(char** map, Object* object, float acceleration, float maxSpeed, int sizeMapY);
void TryJump(char** map, Object* object, float jumpPower, int sizeMapY);

#endif 

