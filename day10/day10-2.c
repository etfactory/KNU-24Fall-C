#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rank {
    VIP = 1,
    GOLD = 2,
    SILVER = 3,
    BRONZE = 4,
    NORMAL = 5
};

struct Customer {
    char* customerName;
    enum rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head = NULL;

struct Customer* create_customer(char* customerName, enum rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    new_customer->customerName = strdup(customerName);
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;

    return new_customer;
}

struct Customer* last_customer() {
    struct Customer* cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    }

    return cur;
}

void insert_customer_sorted(struct Customer* new_customer) {
    struct Customer* cur = head;
    while (cur->next != NULL && (cur->next->rank < new_customer->rank ||
        (cur->next->rank == new_customer-> rank && cur->next->order_amount > new_customer->order_amount) ||
        (cur->next->rank == new_customer-> rank && cur->next->order_amount == new_customer->order_amount && cur->next->point > new_customer->point))) {
        cur = cur->next;
    }
    new_customer->next = cur->next;
    if (cur->next != NULL) {
        cur->next->prev = new_customer;
    }
    cur->next = new_customer;
    new_customer->prev = cur;
}

void print_customers() {
    struct Customer* cur = head->next;
    while(cur != NULL) {
        printf("%s\t\t%d\t%d\t%d\n", cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
}

struct Customer* find_customer(char* customerName) {
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if(strcmp(cur->customerName, strdup(customerName)) == 0) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int delete_customer(char* customerName) {
    struct Customer* prev = head;
    struct Customer* cur = head->next;
    while (cur != NULL) {
        if(strcmp(cur->customerName, strdup(customerName)) == 0) {
            prev->next = cur->next;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

int main() {
    head = (struct Customer*)malloc(sizeof(struct Customer));
    head->next = NULL;
    head->prev = NULL;

    int menu;
    char* customerName = (char*)malloc(sizeof(char));
    enum rank rank;
    int order_amount;
    int point;

    while(1) {
        printf("--------------------\n");
        print_customers();
        printf("--------------------\n");
        printf("1. 고객추가\n");
        printf("2. 고객제거\n");
        printf("3. 종료\n");
        printf("input:");
        scanf_s("%d", &menu);
        switch (menu) {
            case 1:
                printf("고객이름:");
                scanf_s("%s", customerName);
                printf("고객등급(1~5):");
                scanf_s("%d", &rank);
                printf("주문량:");
                scanf_s("%d", &order_amount);
                printf("포인트:");
                scanf_s("%d", &point);

                if(find_customer(customerName)!=NULL) {
                    printf("[!] 이미 저장된 고객입니다.\n");
                } else {
                    if(rank < 1 || rank > 5) {
                        printf("[!] 등급은 1~5 사이의 숫자로 입력해주세요.\n");
                    } else {
                        insert_customer_sorted(create_customer(customerName,rank,order_amount,point));
                    }
                }

                break;
            case 2:
                printf("고객이름:");
                scanf_s("%s", customerName);
                if(find_customer(customerName)!=NULL) {
                    delete_customer(customerName);
                } else {
                    printf("[!] 입력한 고객이 존재하지 않습니다.\n");
                }
                break;
            case 3:
                printf("[!] 프로그램을 종료합니다.\n");

                free(customerName);
                free(head);
                return 0;
            default:
                printf("[!] 번호를 잘못 입력하였습니다..\n");
        }
    }
}