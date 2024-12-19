// 주석에 적혀있지 않은 부분은 최종 보고서에 작성되어 있습니다.
// 202101776 오은택

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

// 게임 범위와 관련된 변수입니다.
// range가 증가할 수록 맵이 줄어듭니다.
int range;
int rangeTemp;

// 아이템의 좌표를 저장하는 변수입니다.
int fruitx, fruity;
int cannotMoveItemX, cannotMoveItemY;
int reverseMoveItemX, reverseMoveItemY;
int fixReverseItemX, fixReverseItemY;
int removeBarricadeX, removeBarricadeY;
int removeBarricadeTemp;

// cannotMoveItem의 횟수와 플래그를 저장하는 변수
int cntCannotMoveItem;
int checkCannotMoveItem;

// Reverse Move Item 플래그 저장 변수
int checkReverseMoveItem;

// 장애물 좌표
int barricadeX[20], barricadeY[20];
int barTemp;

int barCount;

int flag;

// 꼬리
int tailX[100], tailY[100]; // 꼬리의 좌표를 저장하는 변수
int nTail; // 꼬리의 개수

char name[20]; // 닉네임

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
	x = width / 2;
	y = height / 2;

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

	// 장애물 초기화
	barCount = 0;
	barTemp = 0;

	// 범위 초기화
	range = 0;
	rangeTemp = 0;

	removeBarricadeTemp = 0;

	// 아이템 초기화
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
				else if (i == removeBarricadeX && j == removeBarricadeY && removeBarricadeTemp == 1)
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
		default:
			break;
		}
	}
}

void moveSnake() {
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
		default:
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

// 각종 아이템 위치 설정 함수
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

// 아이템이 맵 밖에 위치할 경우 위치 재지정
void replaceItems() {
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
}

// 아이템 설정 함수
void setItems() {
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

	if (score % 40 != 0 && rangeTemp == 1) rangeTemp = 0;

	if (score % 40 == 0 && rangeTemp == 0 && score > 0) {
		range++;
		rangeTemp = 1;
	}

	if (score % 20 != 0 && barTemp == 1) barTemp = 0;

	if (score % 20 == 0 && barTemp == 0 && score > 0) {
		setBarricade();
		// 장애물이 아이템과 겹치지 않도록 설정
		while (barricadeX[barCount-1] == fruitx && barricadeY[barCount-1] == fruity) {
			barricadeX[barCount-1] = rand() % (width-range*2) + range - 1;
			barricadeY[barCount-1] = rand() % (height-range*2) + range - 1;
		}
	}
}

// 게임이 종료되는 조건을 설정하는 함수
void conditionOfGameOver() {
	if (x == 0 || x == height || y == 0 || y == width)
		gameover = 1;

	if (x == range || x == height-range || y == range || y == width-range)
		gameover = 1;

	for (int i = 0; i < barCount; i++) {
		if (x == barricadeX[i] && y == barricadeY[i]) {
			gameover = 1;
		}
	}
}

// Function for the logic behind
// each movement
void logic()
{
	Sleep(200);

	// 뱀의 꼬리 움직임 관련
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

	moveSnake();

	replaceItems();

	conditionOfGameOver();

	setItems();

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
	// 데이터 읽기
	fopen_s(&db, "rank.txt", "rt");

	system("cls");

	printf("Ranking\n");
	printf("======================\n\n");

	if (db == NULL) {
		printf("Did not Play this Game,\n");
	} else {
		while(fscanf_s(db, "%19s\t%d",name,(unsigned)_countof(name), &scoreOfName) != EOF) {
			printf("%3d. %9s\t%d\n",cnt+1,name,scoreOfName);
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

			// 데이터 읽기 및 구조체에 저장
			fopen_s(&db, "rank.txt", "rt");
			if (db != NULL) {
				while(fscanf_s(db, "%19s\t%d", ranks[cnt].name, (unsigned)_countof(ranks[cnt].name), &ranks[cnt].score) != EOF) {
					cnt++;
				}
				fclose(db);
			}

			// 구조체에 게임 결과 저장
			strcpy_s(ranks[cnt].name, sizeof(ranks[cnt].name), name);
			ranks[cnt].score = score;
			cnt++;

			// 구조체 정렬
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

			// DB에 구조체 내용 저장 (정렬 결과 저장)
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