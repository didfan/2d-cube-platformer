#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include "vector.h"
#include "parameters.h"

typedef struct {
	Vector position;
	Vector size;
	int leftOffset;
	int topOffset;
} Camera;

void InitCamera(Camera* camera, Vector position);
void MoveCamera(Camera* camera, Vector movePosition, int mapSizeX, int mapSizeY);

#endif

