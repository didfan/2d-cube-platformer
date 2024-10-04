#include <windows.h>
#include <stdio.h>

#include "parameters.h"
#include "vector.h"
#include "object.h"
#include "objectMovement.h"
#include "level.h"
#include "drawMap.h"
#include "camera.h"
#include "gameState.h"

int main()
{
	Level level;
	level.map = InitLevel(MAP_FILE_NAME, &level);

	Object player;
	Vector playerSize = { SIZE, SIZE };
	InitObject(&player, level.spawn, playerSize, '$');
	PutObjectOnMap(&player, level.map);

	Camera camera;
	InitCamera(&camera, player.position);
	OutputMap(&camera ,level.map, level.sizeY);

	//Game cycle
	while (1)
	{
		while (GetKeyState(VK_ESCAPE) >= 0 && !CheckEnd(0))
		{
			ClearObjectOnMap(&player, level.map);

			if (GetKeyState(VK_SPACE) < 0)
				TryJump(level.map, &player, JUMP_POWER, level.sizeY);
			if (GetKeyState('A') < 0)
				MoveHorizontal(level.map, &player, -1, HORIZONTAL_SPEED, level.sizeY);
			if (GetKeyState('D') < 0)
				MoveHorizontal(level.map, &player, 1, HORIZONTAL_SPEED, level.sizeY);

			VerticalMove(level.map, &player, VERTICAL_ACCELERATION, MAX_VERTICAL_SPEED, level.sizeY);
			MoveCamera(&camera, player.position, level.sizeX, level.sizeY);

			PutObjectOnMap(&player, level.map);
			Sleep(50);

			OutputMap(&camera, level.map, level.sizeY);
		}

		//Check game result
		switch (CheckEnd(0))
		{
			case quit:
				return 0;
			case win:
				ShowFile(VICTORY_LABEL_FILE_NAME);
				break;
			case lose:
				ShowFile(LOSE_LABEL_FILE_NAME);
				break;
		}

		//End or restart game
		printf("\nPress escape to exit\n");
		printf("Press space to restart\n");
		
		while (GetKeyState(VK_ESCAPE) >= 0 && GetKeyState(VK_SPACE) >= 0) {}

		if (GetKeyState(VK_ESCAPE) < 0)
			return 0;
		else if (GetKeyState(VK_SPACE) < 0)
			Restart(&player, &camera, level.map, level.spawn);
	}
	return 0;
}