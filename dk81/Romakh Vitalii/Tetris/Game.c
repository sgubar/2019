#include "Game.h"


int GameState = GAME_PAUSED;

void gameLoop(Field *field) {
	
	int width = field->rows;
	int height = field->cols;

	int nextFigureX = width + 2;
	int nextFigureY = 2;

	int currentFigureX = width / 2 - 2;
	int currentFigureY = 1;

	int firstStart = 0;

	Figure *nextFigure = genereteNextFigure(nextFigureX, nextFigureY);
	Figure *currentFigure = genereteNextFigure(currentFigureX, currentFigureY);


	int dy = 1;
	int dx = 0;

	int  movementRes = 0;
	int  intersectionRes = 0;
	int  checkLineRes = OK;
	
	int score = 0;

	while (GameState == GAME_RUNNING) {
		updateField(field,currentFigure, nextFigure, score);

		if (firstStart == 0) {
			deleteFigure(nextFigure);
			nextFigure = genereteNextFigure(nextFigureX, nextFigureY);
			firstStart = 1;
		}

		intersectionRes = isIntersection(field, currentFigure);

		if (intersectionRes == TOUCH_Y  || intersectionRes == TOUCH_ELEMENT) {
			saveFigureToField(field, currentFigure);

			deleteFigure(currentFigure);
			currentFigure = nextFigure;

			currentFigure->x = currentFigureX;
			currentFigure->y = currentFigureY;

			nextFigure = genereteNextFigure(nextFigureX, nextFigureY);
		}	


		delayAndMove(500, currentFigure, field, nextFigure, score);

		checkLineRes = checkEndedLine(field);

		if (checkLineRes != OK && checkLineRes != ERROR) {
			shiftRowsInArrayToBottom(field, checkLineRes);
			score += 10;
		}
	}
}

int startGame(int cols, int rows) {
	Field *field = createField(cols, rows);
	GameState = GAME_RUNNING;
	gameLoop(field);
	return GameState;
}

int pauseGame() {
	GameState = GAME_PAUSED;
	return GameState;
}

int continueGame() {
	GameState = GAME_RUNNING;
	return GameState;
}

Figure *genereteNextFigure(int x, int y) {
	srand(time(NULL));

	int max = LINE_D;
	int min = LINE;
	Figure *figure;

	int figureType = (rand() % (max - min + 1)) + min;

	figure = createFigure(x, y, figureType);
	return figure;
}

int isIntersection(Field *field, Figure *figure) {
		if (field == NULL || figure == NULL) {
			return ERROR;
		}


		for (int y = figure->y; y < figure->y + figure->size; y++) // y
		{
			for (int x = figure->x; x < figure->x + figure->size; x++) //x
			{
				
				if ( figure->dotArray[x - figure->x][y - figure->y] == 1 && ( y >= field->cols - 1)) {
					return TOUCH_Y;
				}
				else if (y + 1 < field->cols && (field->fieldArray[y + 1][x] == 1 && figure->dotArray[x - figure->x][y - figure->y] == 1)) {
					return TOUCH_ELEMENT;
				}
				else if (x <= -1 || x >= field->rows) {
					return TOUCH_X;
				}
			}
		}
		

	
	return 0;
}

int saveFigureToField(Field *field, Figure *figure) {
	if (field == NULL || figure == NULL) {
		return ERROR;
	}


	for (int y = figure->y; y < figure->y + figure->size; y++) // y
	{
		for (int x = figure->x; x < figure->x + figure->size; x++) //x
		{
			if (figure->dotArray[x - figure->x][y - figure->y] == 1 && y < field->rows) {
				field->fieldArray[y][x] = figure->dotArray[x - figure->x][y - figure->y];
			}
		}
	}

	return OK;
}



int getInput() {
	char c = 0;

	if (_kbhit())

	{
		c = _getch();
	}

	if (c == 's' || c == 'S') {
		return MOVE_TO_BOTTOM;
	}
	
	if (c == 'a' || c == 'A') {
		return MOVE_TO_LEFT;
	}

	if (c == 'd' || c == 'D') {
		return MOVE_TO_RIGHT;
	}

	if (c == 'e' || c == 'E') {
		return ROTATE_CLOCKWISE;
	}

	if (c == 'q' || c == 'Q') {
		return ROTATE_COUNTERCLOCKWISE;
	}
	return 0;
}



int delay(int millis) {
	int startTime = clock();
	while (clock() < startTime + millis) {
	}
	return 1;
}

int delayForGetInput(int millis) {
	int startTime = clock();
	int res = 0;
	while (clock() < startTime + millis) {
		res = getInput();
		if (res != 0) {
			return res;
	  }
	}
	return 0;
}

int delayAndMove(int millis, Figure *figure, Field *field, Figure *nextFigure, int score) {
	int movementRes = 0;
	int dx = 0;
	int dy = 0;

	int startTime = clock();

	while (clock() < startTime + millis) {
		movementRes = getInput();
		if (movementRes!= 0) {
				if (movementRes == MOVE_TO_BOTTOM) {
					dx = 0;
					dy = 1;
				}

				if (movementRes == MOVE_TO_LEFT) {
					dx = -1;
					dy = 0;
				}

				if (movementRes == MOVE_TO_RIGHT) {
					dx = 1;
					dy = 0;
				}

				if (movementRes == ROTATE_CLOCKWISE) {
					rotateFigure(figure, CLOCKWISE);
					dy = 0;
				}

				if (movementRes == ROTATE_COUNTERCLOCKWISE) {
					rotateFigure(figure, COUNTERCLOCKWISE);
					dy = 0;
				}

				moveFigure(figure, dx, dy);

				
				movementRes = isIntersection(field, figure);
				if (movementRes == TOUCH_Y || movementRes == TOUCH_ELEMENT || movementRes == TOUCH_X) {
					moveFigure(figure, dx * (-1), dy * (-1));
				}

				updateField(field, figure, nextFigure, score);
			}
	}
	dy = 1;
	dx = 0;
	moveFigure(figure, dx, dy);

	return 0;
}

void updateField(Field *field, Figure *currentFigure, Figure *nextFigure, int score) {
	system("cls");
	printField(field, currentFigure, nextFigure, score);
}