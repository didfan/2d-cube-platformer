#ifndef DRAW_MAP_H_INCLUDED
#define DRAW_MAP_H_INCLUDED

#include <windows.h>
#include <stdio.h>

#include "vector.h"
#include "object.h"
#include "camera.h"

void ClearObjectOnMap(const Object* object, char** map);
void PutObjectOnMap(const Object* object, char** map);
void OutputMap(Camera* camera, char** map, int sizeY);

#endif
