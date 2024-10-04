#include "level.h"

void FindFileSize(const char* fileName, int* sizeX, int* sizeY)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
		fprintf(stderr, "Error: can't open file\n");

	int currentLine = 0, longestLine = 0;
	int longestColumn = 0;
	char ch;

	while ((ch = fgetc(file)) != EOF)
	{
		currentLine++;
		if (ch == '\n')
		{
			if (longestLine < currentLine)
				longestLine = currentLine;
			currentLine = 0;
			longestColumn++;
		}
	}
	fclose(file);

	*sizeX = longestLine + 1;
	if (*sizeX < SIZE_CAMERA_X)
		*sizeX = SIZE_CAMERA_X;

	*sizeY = longestColumn + 1;
}

char** InitLevel(const char* fileName, Level* level)
{
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
		fprintf(stderr, "Error: can't open file\n");

	FindFileSize(fileName, &level->sizeX, &level->sizeY);

	int rightSizeY = level->sizeY < SIZE_CAMERA_Y ? SIZE_CAMERA_Y : level->sizeY;
	int realLength = 0;

	char** map = malloc(sizeof(char*) * level->sizeY);
	for (int i = 0; i < rightSizeY; i++)
	{
		//Read map line
		map[i] = malloc(sizeof(char) * level->sizeX);
		if (i < level->sizeY)
		{
			fgets(map[i], level->sizeX, file);
			realLength = strlen(map[i]);
		}
		else realLength = 0;

		//equalize size of all lines
		memset(map[i] + realLength - 1, ' ', level->sizeX - realLength);
		map[i][level->sizeX - 1] = '\0';

		//Find player's spawn point  
		for (int j = 0; j < level->sizeX; j++)
			if (map[i][j] == SPAWN_SYMBOL)
			{
				SetVector(&level->spawn, j, i);
				map[i][j] = ' ';
			}
	}
	fclose(file);
	return map;
}