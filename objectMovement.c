#include "objectMovement.h"

int ReturnSingOfNumber(float number)
{
	if (number > 0) return 1;
	if (number < 0) return -1;
	return 0;
}

void MoveHorizontal(char** map, Object* object, int directionX, float speed, int sizeMapY)
{
	int checkPosition = object->position.x + (directionX == 1 ? object->size.x : directionX);

	Vector start = { checkPosition, object->position.y };
	Vector end = { checkPosition, object->position.y + object->size.y - 1 };
	if (CheckRangePositionsOnBlock(map, start, end, sizeMapY) == 0)
		object->position.x += (float)directionX * (float)speed;
}

void VerticalMove(char** map, Object* object, float acceleration, float maxSpeed, int sizeMapY)
{
	int checkPosition = ReturnSingOfNumber(object->verticalSpeed) >= 0 ? object->position.y + object->size.y : object->position.y - 1;

	Vector start = { object->position.x, checkPosition };
	Vector end = { object->position.x + object->size.x - 1, checkPosition };
	if (checkPosition >= 0 && CheckRangePositionsOnBlock(map, start, end, sizeMapY) == 0)
	{
		if (object->verticalSpeed < maxSpeed)
			object->verticalSpeed += acceleration;
		object->position.y += object->verticalSpeed;
	}
	else object->verticalSpeed = 0;
}

void TryJump(char** map, Object* object, float jumpPower, int sizeMapY)
{
	Vector start = { object->position.x, object->position.y + object->size.y };
	Vector end = { object->position.x + object->size.x - 1, object->position.y + object->size.y };
	if (CheckRangePositionsOnBlock(map, start, end, sizeMapY))
		object->verticalSpeed = -jumpPower;
}