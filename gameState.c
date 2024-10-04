#include "gameState.h"

void ShowFile(const char* fileName)
{
	system("cls");
	FILE* file = fopen(fileName, "r");
	char* buffer = malloc(BUFFER_SIZE);
	while (fgets(buffer, BUFFER_SIZE - 1, file))
		printf("%s", buffer);
}

int CheckEnd(int setValue)
{
	static int isEnd = 0;
	if (setValue != 0 && isEnd == 0)
		isEnd += setValue;
	else if (setValue < 0)
		isEnd -= isEnd;
		
	return isEnd;
}

void Win()
{
	CheckEnd(1);
}

void Lose()
{
	CheckEnd(2);
}

void Restart(Object* player, Camera* camera, char** map, Vector spawn)
{
	ClearObjectOnMap(player, map);
	player->position = spawn;
	PutObjectOnMap(player, map);
	InitCamera(camera, player->position);
	system("cls");
	CheckEnd(-1);
}
