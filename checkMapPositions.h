#ifndef CHECK_MAP_POSITIONS_H_INCLUDED
#define CHECK_MAP_POSITIONS_H_INCLUDED

#include "vector.h"
#include "gameState.h"
#include "parameters.h"
#include "level.h"

int CheckPositionOnBlock(char** map, int x, int y, int sizeMapY);
int CheckRangePositionsOnBlock(char** map, Vector start, Vector end, int sizeMapY);

#endif


