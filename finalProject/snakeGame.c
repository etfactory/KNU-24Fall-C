#include <conio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h>
#include <time.h>
#include <Windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y;

int countOfMoving;

// Range of Game
int range;
int rangeTemp;

// Item X, Y
int fruitx, fruity;
int cannotMoveItemX, cannotMoveItemY;
int reverseMoveItemX, reverseMoveItemY;
int fixReverseItemX, fixReverseItemY;
int removeBarricadeX, removeBarricadeY;
int removeBarricadeTemp;

// cannotMoveItem Value
int cntCannotMoveItem;
int checkCannotMoveItem;

// Reverse Move Item Value
int checkReverseMoveItem;

// Barricade X, Y
int barricadeX[20], barricadeY[20];
int barTemp;

int barCount;

int flag;

// Tail
int tailX[100], tailY[100]; // Arrays to store the positions of the tail segments
int nTail; // Number of tail segments

char name[20];

struct rank {
	char name[20];
	int score;
};

// Function to generate the fruit
// within the boundary
void setup()
{
	srand(time(NULL));

	gameover = 0;

	// Stores height and width
	x = height / 2;
	y = width / 2;

	nTail = 0;

	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % width;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % height;
	}

	checkReverseMoveItem = 0;

	// Set Barricade
	barCount = 0;
	barTemp = 0;

	// Set Default Range
	range = 0;
	rangeTemp = 0;

	removeBarricadeTemp = 0;

	// Set Item Location
	cntCannotMoveItem = 0;
	cannotMoveItemX = 0;
	while (cannotMoveItemX == 0)
		cannotMoveItemX = rand() % width;
	cannotMoveItemY = 0;
	while (cannotMoveItemY == 0)
		cannotMoveItemY = rand() % height;

	reverseMoveItemX = 0;
	while (reverseMoveItemX == 0)
		reverseMoveItemX = rand() % width;
	reverseMoveItemY = 0;
	while (reverseMoveItemY == 0)
		reverseMoveItemY = rand() % height;

	fixReverseItemX = 0;
	while (fixReverseItemX == 0)
		fixReverseItemX = rand() % width;
	fixReverseItemY = 0;
	while (fixReverseItemY == 0)
		fixReverseItemY = rand() % height;

	countOfMoving = 0;
	score = 0;
}

// Function to draw the boundaries
void draw()
{
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == height - 1) {
				printf("X");
			} else if (i == range
				|| i == width - range - 1
				|| j == range
				|| j == height - range- 1) {
				printf("+");
			} else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx && j == fruity)
					printf("#");
				else if (i == cannotMoveItemX && j == cannotMoveItemY)
					printf("!");
				else if (i == reverseMoveItemX && j == reverseMoveItemY && checkReverseMoveItem == 0)
					printf("@");
				else if (i == fixReverseItemX && j == fixReverseItemY && checkReverseMoveItem == 1)
					printf("~");
				else if (i == removeBarricadeX && j == removeBarricadeY)
					printf("*");
				else {
					int isTail = 0;
					int isBar = 0;
					for (int k = 0; k < nTail; k++) {
						if (i == tailX[k] && j == tailY[k]) {
							printf("o");
							isTail = 1;
							break;
						}
					}
					for (int k = 0; k < barCount; k++) {
						if (i == barricadeX[k] && j == barricadeY[k]) {
							printf("X");
							isBar = 1;
							break;
						}
					}
					if (!isTail && !isBar) {
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}

	// Print the score after the
	// game ends
	printf("name : %s\n", name);
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game\n");

}

// Function to take the input
void input() {
	if (_kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}

void reverseInput() {
	if (_kbhit()) {
		switch (getch()) {
			case 'a':
				flag = 3;
			break;
			case 's':
				flag = 4;
			break;
			case 'd':
				flag = 1;
			break;
			case 'w':
				flag = 2;
			break;
			case 'x':
				gameover = 1;
			break;
		}
	}
}

void cannotMoveItemOn(int flag) {
	if (_kbhit()) {
		if (getch() == 'x') {
			gameover = 1;
		}
	}
	switch (flag) {
		case 1:
			y--;
		break;
		case 2:
			x++;
		break;
		case 3:
			y++;
		break;
		case 4:
			x--;
		break;
		default:
			break;
	}
}

void setFruit() {
	fruitx = 0;
	while (fruitx == 0) {
		fruitx = rand() % (width-range*2) + range - 1;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % (height-range*2) + range - 1;
	}
}

void setBarricade() {
	barricadeX[barCount] = rand() % (width-range*2) + range - 1;
	barricadeY[barCount] = rand() % (height-range*2) + range - 1;
	barCount++;
	barTemp = 1;
}

void setRemoveBarricade() {
	removeBarricadeX = 0;
	while (removeBarricadeX == 0) {
		removeBarricadeX = rand() % (width-range*2) + range - 1;
	}
	removeBarricadeY = 0;
	while (removeBarricadeY == 0) {
		removeBarricadeY = rand() % (height-range*2) + range - 1;
	}
}

void setCannotMoveItem() {
	checkCannotMoveItem = 1;
	cannotMoveItemX = rand() % (width-range*2) + range - 1;
	cannotMoveItemY = rand() % (height-range*2) + range - 1;
}

void setReverseMoveItem() {
	checkReverseMoveItem = 1;
	reverseMoveItemX = rand() % (width-range*2) + range - 1;
	reverseMoveItemY = rand() % (height-range*2) + range - 1;
}

void setFixReverseItem() {
	checkReverseMoveItem = 0;
	fixReverseItemX = rand() % (width-range*2) + range - 1;
	fixReverseItemY = rand() % (height-range*2) + range - 1;
}

// Function for the logic behind
// each movement
void logic()
{
	Sleep(200);

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (flag) {
		case 1:
			y--;
		break;
		case 2:
			x++;
		break;
		case 3:
			y++;
		break;
		case 4:
			x--;
		break;
		default:
			break;
	}
	// If Items is out of Range
	if (fruitx <= range || fruitx >= width-range-1 ||
		fruity <= range || fruity >= height-range-1)
		setFruit();

	if ((removeBarricadeX <= range || removeBarricadeX >= width-range-1 ||
		removeBarricadeY <= range || removeBarricadeY >= height-range-1) && barCount > 0)
		setRemoveBarricade();

	if (reverseMoveItemX <= range || reverseMoveItemX >= width-range-1 ||
		reverseMoveItemY <= range || reverseMoveItemY >= height-range-1)
		setReverseMoveItem();

	if (fixReverseItemX <= range || fixReverseItemX >= width-range-1 ||
		fixReverseItemY <= range || fixReverseItemY >= height-range-1)
		setFixReverseItem();

	if (cannotMoveItemX <= range || cannotMoveItemX >= width-range-1 ||
		cannotMoveItemY <= range || cannotMoveItemY >= height-range-1)
		setCannotMoveItem();

	// Snake eats Items
	if (x == fruitx && y == fruity) {
		setFruit();
		score += 10;
		nTail++;
	}

	if (barCount > 0 && removeBarricadeTemp == 0) {
		setRemoveBarricade();
		removeBarricadeTemp = 1;
	}

	if (x == removeBarricadeX && y == removeBarricadeY) {
		barCount = 0;
		range = 0;
		removeBarricadeTemp = 0;
	}

	if (x == reverseMoveItemX && y == reverseMoveItemY && checkReverseMoveItem == 0) {
		setReverseMoveItem();
	}

	if (x == fixReverseItemX && y == fixReverseItemY && checkReverseMoveItem == 1) {
		setFixReverseItem();
	}

	if (x == cannotMoveItemX && y == cannotMoveItemY) {
		setCannotMoveItem();
	}

	if (checkCannotMoveItem == 1) {
		if(cntCannotMoveItem == 3) {
			checkCannotMoveItem = 0;
			cntCannotMoveItem = 0;
		}
		cntCannotMoveItem++;
	}

	if (x == 0 || x == height || y == 0 || y == width)
		gameover = 1;

	if (x == range || x == height-range || y == range || y == width-range)
		gameover = 1;

	for (int i = 0; i < barCount; i++) {
		if (x == barricadeX[i] && y == barricadeY[i]) {
			gameover = 1;
		}
	}

	if (score % 40 != 0 && rangeTemp == 1) rangeTemp = 0;

	if (score % 40 == 0 && rangeTemp == 0 && score > 0) {
		range++;
		rangeTemp = 1;
	}

	if (score % 20 != 0 && barTemp == 1) barTemp = 0;

	if (score % 20 == 0 && barTemp == 0 && score > 0) {
		setBarricade();
		// Check the barricade is not on the fruit
		while (barricadeX[barCount-1] == fruitx && barricadeY[barCount-1] == fruity) {
			barricadeX[barCount-1] = rand() % (width-range*2) + range - 1;
			barricadeY[barCount-1] = rand() % (height-range*2) + range - 1;
		}
	}

	countOfMoving++;
}

int intro() {
	int answer=0;

	printf("===== SNAKE GAME =====\n\n");
	printf("1. Start Game\n");
	printf("2. Rank\n");
	printf("3. Exit\n\n");
	printf("======================\n");
	printf("Select the menu: ");
	scanf_s("%d", &answer);

	return answer;
}

void setName(char name[]) {
	printf("Enter your name: ");
	scanf_s("%s", name, sizeof(name));
}

void rank() {
	FILE* db;
	char name[20];
	int scoreOfName;
	int cnt = 0;
	// Open the file in read mode
	fopen_s(&db, "rank.txt", "rt");

	system("cls");

	printf("Ranking\n");
	printf("======================\n\n");

	if (db == NULL) {
		printf("Did not Play this Game,\n");
	} else {
		struct rank ranks[100];

		while(fscanf_s(db, "%19s\t%d",name,(unsigned)_countof(name), &scoreOfName) != EOF) {
			printf("%3d. %9s\t%d\n",cnt,name,scoreOfName);
			cnt++;
		}
		fclose(db);
	}
	printf("\n");
	printf("======================\n");
}

void gameOver(char name[]) {
	system("cls");
	printf("Game Over\n");
	printf("Your Score: %d\n", score);
	printf("Do you want to save your score? (Y/N): ");
	char answer;
	while(1) {
		scanf_s(" %c", &answer);
		getchar();
		if (answer == 'Y' || answer == 'y') {
			FILE* db;
			struct rank ranks[100];
			int cnt = 0;

			// Open the file in read mode
			fopen_s(&db, "rank.txt", "rt");
			if (db != NULL) {
				while(fscanf_s(db, "%19s\t%d", ranks[cnt].name, (unsigned)_countof(ranks[cnt].name), &ranks[cnt].score) != EOF) {
					cnt++;
				}
				fclose(db);
			}

			// Add the new score
			strcpy_s(ranks[cnt].name, sizeof(ranks[cnt].name), name);
			ranks[cnt].score = score;
			cnt++;

			// Sort the scores
			struct rank temp;
			for (int i = 0; i < cnt - 1; i++) {
				for (int j = i + 1; j < cnt; j++) {
					if (ranks[i].score < ranks[j].score) {
						temp = ranks[i];
						ranks[i] = ranks[j];
						ranks[j] = temp;
					}
				}
			}

			// Open the file in write mode
			fopen_s(&db, "rank.txt", "wt");
			for (int i = 0; i < cnt; i++) {
				fprintf(db, "%s\t%d\n", ranks[i].name, ranks[i].score);
			}
			fclose(db);

			printf("Your score is saved\n");
			break;
		} else if (answer == 'N' || answer == 'n') {
			printf("Your score is not saved\n");
			break;
		} else {
			printf("Please select the correct menu\n");
		}
	}
}

void main() {
	while(1) {
		int answer = intro();
		gameover = 0;
		switch (answer) {
			case 1:
				setName(name);

				setup();

				while(!gameover) {
					// Sleep(200);
					draw();
					if (checkCannotMoveItem == 1) {
						cannotMoveItemOn(flag);
					}
					if (checkReverseMoveItem == 1) {
						reverseInput();
					} else {
						input();
					}
					logic();
				}

				if (gameover) {
					gameOver(name);
				}
				break;
			case 2:
				rank();
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("Please select the correct menu\n");
				break;
		}
	}


	// int m, n;

	// Generate boundary 
	// setup();

	// Until the game is over 
	// while (!gameover) {
	//
	// 	// Function Call
	// 	draw();
	// 	input();
	// 	logic();
	// }
}