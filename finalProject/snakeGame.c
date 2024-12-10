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

// Item X, Y
int fruitx, fruity;
int cannotMoveItemX, cannotMoveItemY;
int reverseMoveItemX, reverseMoveItemY;
int fixRemoveItemX, fixRemoveItemY;
int removeBarricadeX, removeBarricadeY;

// cannotMoveItem Count
int cntCannotMoveItem;
int checkCannotMoveItem;

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
		fruitx = rand() % 20;
	}

	fruity = 0;
	while (fruity == 0) {
		fruity = rand() % 20;
	}

	cntCannotMoveItem = 0;
	cannotMoveItemX = 0;
	while (cannotMoveItemX == 0)
		cannotMoveItemX = rand() % width;
	cannotMoveItemY = 0;
	while (cannotMoveItemY == 0)
		cannotMoveItemY = rand() % height;

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
			} else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruitx && j == fruity)
					printf("#");
				else if (i == cannotMoveItemX && j == cannotMoveItemY)
					printf("!");
				else if (i == reverseMoveItemX && j == reverseMoveItemY)
					printf("@");
				else if (i == fixRemoveItemX && j == fixRemoveItemY)
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

	if (x == 0 || x == height || y == 0 || y == width)
		gameover = 1;

	for (int i = 0; i < barCount; i++) {
		if (x == barricadeX[i] && y == barricadeY[i]) {
			gameover = 1;
		}
	}

	if (x == fruitx && y == fruity) {
		fruitx = 0;
		while (fruitx == 0) {
			fruitx = rand() % width;
		}

		fruity = 0;
		while (fruity == 0) {
			fruity = rand() % height;
		}

		score += 10;
		nTail++;
	}

	if (x == cannotMoveItemX && y == cannotMoveItemY) {
		checkCannotMoveItem = 1;
		cannotMoveItemX = rand() % width;
		cannotMoveItemY = rand() % height;
	}

	if (checkCannotMoveItem == 1) {
		if(cntCannotMoveItem == 3)
			checkCannotMoveItem = 0;
		cntCannotMoveItem++;
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
		while(fscanf_s(db, "%19s\t%d", name, (unsigned)_countof(name), &scoreOfName) != EOF) {
			strcpy_s(ranks[cnt].name,sizeof(ranks[cnt].name), name);
			ranks[cnt].score = scoreOfName;
			cnt++;
		}
		// Sort
		char nameTEMP[20];
		int scoreTEMP;
		for(int i=0; i<cnt; i++) {
			for(int j=0; j<cnt-i; j++) {
				if (ranks[j].score < ranks[j+1].score) {
					scoreTEMP = ranks[j].score;
					ranks[j].score = ranks[j+1].score;
					ranks[j+1].score = scoreTEMP;

					strcpy_s(nameTEMP,sizeof(nameTEMP), ranks[j].name);
					strcpy_s(ranks[j].name,sizeof(ranks[j].name), ranks[j+1].name);
					strcpy_s(ranks[j+1].name,sizeof(ranks[j+1].name), nameTEMP);
				}
			}
		}
		for(int i=1; i<=cnt; i++) {
			printf("%3d. %9s\t%d\n", i, ranks[i].name, ranks[i].score);
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
			fopen_s(&db, "rank.txt", "a");
			fprintf(db, "%s\t%d\n", name, score);
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

void main()
{
	FILE* db;

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
					if(checkCannotMoveItem == 0) {
						input();
					} else
						cannotMoveItemOn(flag);
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