#include "object.h"

void InitObject(Object* object, Vector position, Vector size, char symbol)
{
	object->position = position;
	object->size = size;
	object->verticalSpeed = 0;
	object->symbol = symbol;
}