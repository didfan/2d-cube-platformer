#include "checkMapPositions.h"

int CheckPositionOnBlock(char** map, int x, int y, int sizeMapY)
{

	if (y >= sizeMapY)
	{
		Lose();
		return 1;
	}
	else if(map[y][x] == SPIKE_SYMBOL)
		Lose();
	else if (map[y][x] == END_SYMBOL)
		 Win();
	return map[y][x] != ' ';
}

int CheckRangePositionsOnBlock(char** map, Vector start, Vector end, int sizeMapY)
{
	int isHaveBlocks = 0;
	for (int i = start.y; i <= end.y; i++)
		for (int j = start.x; j <= end.x; j++)
			if (CheckPositionOnBlock(map, j, i, sizeMapY))
				isHaveBlocks = 1;
	return isHaveBlocks;
}
