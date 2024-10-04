#include "camera.h"

void InitCamera(Camera* camera, Vector position)
{
	camera->size.x = SIZE_CAMERA_X;
	camera->size.y = SIZE_CAMERA_Y;
    camera->leftOffset = SIZE_CAMERA_X / 2;
	camera->topOffset = SIZE_CAMERA_Y / 2;

	if (0 < position.x - camera->leftOffset)
		camera->position.x = position.x;
	else camera->position.x = camera->leftOffset;

	if (0 < position.y - camera->topOffset)
		camera->position.y = position.y;
	else camera->position.y = camera->topOffset;
}

void MoveCamera(Camera* camera, Vector movePosition, int mapSizeX, int mapSizeY)
{
	if (0 < movePosition.x - camera->leftOffset && movePosition.x + camera->leftOffset < mapSizeX)
		camera->position.x = movePosition.x;
	
	if (0 < movePosition.y - camera->topOffset && movePosition.y + camera->topOffset < mapSizeY)
		camera->position.y = movePosition.y;
}
