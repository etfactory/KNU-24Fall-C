/* 1. 학생삽입(노드생성)
 * 1-1. 동일한 이름을 갖는 학생은 X
 * 2. 전체 학생 출력(노드순회)
 * 3. 학생삭제(노드삭제)
 *
 * 연결리스트에 데이터 삽입 시 정렬된 위치에 삽입
 * 99,70 <- 80 삽입하면 99,80,70
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    char name[20];
    int score;
    struct NODE* link;
};

struct NODE* head = NULL;

struct NODE* create_node(char name[], int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->link = NULL;

    return new_node;
}

struct NODE* last_node() {
    struct NODE* cur = head;
    while(cur->link != NULL) {
        cur = cur->link;
    }

    return cur;
}

void insert_node_last(struct NODE* new_node) {
    struct NODE* last = last_node();

    last->link = new_node;
}

void insert_node_sorted(struct NODE* new_node) {
    struct NODE* cur = head;
    while (cur->link != NULL && cur->link->score > new_node->score) {
        cur = cur->link;
    }
    new_node->link = cur->link;
    cur->link = new_node;
}

void print_nodes() {
    struct NODE* cur = head->link;
    while(cur != NULL) {
        printf("%s\t:\t%d\n", cur->name, cur->score);
        cur = cur->link;
    }
}

struct NODE* find_node(char name[]) {
    struct NODE* cur = head->link;
    while (cur != NULL) {
        if(strcmp(cur->name, name) == 0) {
            return cur;
        }
        cur = cur->link;
    }
    return NULL;
}

int delete_node(char name[]) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;
    while (cur!=NULL) {
        if(strcmp(cur->name, name) == 0) {
            prev->link = cur->link;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->link;
    }
    return 0;
}

int main() {
    int menu;
    char name[20];
    int score;
    struct NODE* result;

    head = (struct NODE*)malloc(sizeof(struct NODE));
    head->link = NULL;

    while(1) {
        printf("------------------\n");
        print_nodes();
        printf("------------------\n");
        printf("1. 학생의 성적을 입력\n2. 학생의 정보 제거\n3. 프로그램 종료\n");
        printf("input:");
        scanf_s("%d", &menu);
        switch(menu) {
            case 1:
                printf("학생 이름:");
                scanf_s("%s", name, sizeof(name));
                printf("%s 성적:", name);
                scanf_s("%d", &score);
                if(find_node(name) == NULL) {
                    insert_node_sorted(create_node(name, score));
                } else {
                    printf("[ ! ] 이미 존재하는 학생입니다.\n");
                }
                break;
            case 2:
                printf("학생 이름:");
                scanf_s("%s", name, sizeof(name));
                if(delete_node(name) == 0) {
                    printf("존재하지 않는 학생입니다.\n");
                } else {
                    delete_node(name);
                }
                break;
            case 3:
                printf("프로그램을 종료합니다.\n");
                printf("------------------\n");
                return 0;
            default:
                printf("번호를 잘못 입력하였습니다.\n");
                break;
        }
    }
}