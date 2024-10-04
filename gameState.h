#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS 
#define BUFFER_SIZE 256

#include <stdlib.h>
#include <stdio.h>

#include "vector.h"
#include "object.h"
#include "drawMap.h"
#include "camera.h"

enum { quit = 0, win = 1, lose = 2};

void ShowFile(const char* fileName);
int CheckEnd(int setValue);
void Win();
void Lose();
void Restart(Object* player, Camera* camera, char** map, Vector spawn);

#endif