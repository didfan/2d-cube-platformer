#include "drawMap.h"

void PutObjectOnMapWithSymbol(const Object* object, const char symbol, char** map)
{
	int ix = (int)object->position.x;
	int iy = (int)object->position.y;

	for (int i = iy; i < (iy + object->size.y); i++)
		for (int j = ix; j < (ix + object->size.x); j++)
			map[i][j] = symbol;
}

void ClearObjectOnMap(const Object* object, char** map)
{
	PutObjectOnMapWithSymbol(object, ' ', map);
}

void PutObjectOnMap(const Object* object, char** map)
{
	PutObjectOnMapWithSymbol(object, object->symbol, map);
}

void SetConsoleCursorPos(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void OutputMap(Camera* camera, char** map, int sizeY)
{
	Vector start = { camera->position.x - camera->leftOffset, camera->position.y - camera->topOffset };
	Vector end = { camera->position.x + camera->leftOffset, camera->position.y + camera->topOffset };
	SetConsoleCursorPos(0, 0);
	for (int i = start.y; i < end.y; i++)
	{
		for (int j = start.x; j < end.x; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}

