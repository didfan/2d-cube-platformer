#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"
#include "parameters.h"

typedef struct
{
	char** map;
	int sizeX, sizeY;
	Vector spawn;
} Level;

char** InitLevel(const char* fileName, Level* level);

#endif
