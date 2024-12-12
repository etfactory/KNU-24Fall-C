/*
conio.h : console input/output header
stdio.h : standard input/output header
stdlib.h : standard library header
io.h : input/output header
Windows.h : Windows header

setup() : generate the fruit within the boundary
draw() : draw the boundaries
input() : take the input
logic() : logic behind each movement
main() : main function
 */

#include <conio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h>
#include <Windows.h>

int i, j, height = 20, width = 20;
int gameover, score;
int x, y;

int countOfMoving;

// Range of Game
int range;

// Item X, Y
int fruitx, fruity;
int cannotMoveItemX, cannotMoveItemY;
int reverseMoveItemX, reverseMoveItemY;
int fixRemoveItemX, fixRemoveItemY;
int removeBarricadeX, removeBarricadeY;

// cannotMoveItem Value
int cntCannotMoveItem;
int checkCannotMoveItem;

// Reverse Move Item Value
int checkReverseMoveItem;

// Barricade X, Y
int barricadeX[20], barricadeY[20];

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

	// Set Default Range
	range = 0;

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

	fixRemoveItemX = 0;
	while (fixRemoveItemX == 0)
		fixRemoveItemX = rand() % width;
	fixRemoveItemY = 0;
	while (fixRemoveItemY == 0)
		fixRemoveItemY = rand() % height;

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
				|| j == height - range - 1) {
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
				else if (i == fixRemoveItemX && j == fixRemoveItemY && checkReverseMoveItem == 1)
					printf("~");
				else if (i == removeBarricadeX && j == removeBarricadeY)
					printf("*");
				else {
					int isTail = 0;
					for (int k = 0; k < nTail; k++) {
						if (i == tailX[k] && j == tailY[k]) {
							printf("o");
							isTail = 1;
							break;
						}
						if (i == barricadeX[k] && j == barricadeY[k]) {
							printf("B");
							isTail = 1;
							break;
						}
					}
					if (!isTail) {
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

	// Fruit Location Fix
	if ((fruitx <= range-1 || fruitx >= width-range-1)
		&& fruity <= range-1 || fruity >= height-range-1) {
		fruitx = 0;
		while (fruitx == 0) {
			fruitx = rand() % width - range;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % height - range;
		}
	}
	if ((reverseMoveItemX <= range-1 || reverseMoveItemX >= width-range-1)
			&& reverseMoveItemY <= range-1 || reverseMoveItemY >= height-range-1) {
		reverseMoveItemX = 0;
		while (reverseMoveItemX == 0) {
			reverseMoveItemX = rand() % width - range;
		}

		reverseMoveItemY = 0;
		while (reverseMoveItemY == 0) {
			reverseMoveItemY = rand() % height - range;
		}
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

	if (x == fruitx && y == fruity) {
		fruitx = 0;
		while (fruitx == 0) {
			fruitx = rand() % width - range;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % height - range;
		}

		score += 10;
		nTail++;
	}

	if (x == reverseMoveItemX && y == reverseMoveItemY && checkReverseMoveItem == 0) {
		checkReverseMoveItem = 1;
		reverseMoveItemX = rand() % width - range;
		reverseMoveItemY = rand() % height - range;
	}

	if (x == fixRemoveItemX && y == fixRemoveItemY && checkReverseMoveItem == 1) {
		checkReverseMoveItem = 0;
		fixRemoveItemX = rand() % width - range;
		fixRemoveItemY = rand() % height - range;
	}

	if (x == cannotMoveItemX && y == cannotMoveItemY) {
		checkCannotMoveItem = 1;
		cannotMoveItemX = rand() % width - range;
		cannotMoveItemY = rand() % height - range;
	}

	if (checkCannotMoveItem == 1) {
		if(cntCannotMoveItem == 3) {
			checkCannotMoveItem = 0;
			cntCannotMoveItem = 0;
		}
		cntCannotMoveItem++;
	}

	if (countOfMoving > 50) {
		if (countOfMoving % 50 == 0) {
			range++;
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