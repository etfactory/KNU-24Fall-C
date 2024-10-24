#include <stdio.h>

typedef struct {
    int x;
    int y;
    int z;
} Vector;

Vector add(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

Vector sub(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

//외적
Vector cross(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

//내적
int dot(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

int main() {
    int x1, y1, z1, x2, y2, z2;
    printf("첫 번째 벡터(x,y,z):");
    scanf_s("%d %d %d", &x1, &y1, &z1);
    printf("두 번째 벡터(x,y,z):");
    scanf_s("%d %d %d", &x2, &y2, &z2);
    Vector v1 = {x1, y1, z1};
    Vector v2 = {x2, y2, z2};

    Vector result;

    printf("입력된 첫번째 벡터 : (%d, %d, %d)\n", v1.x, v1.y, v1.z);
    printf("입력된 두번째 벡터 : (%d, %d, %d)\n", v2.x, v2.y, v2.z);
    printf("------------------\n");
    printf("1. 벡터의 합\n2. 벡터의 차\n3. 벡터의 외적\n4. 벡터의 내적\n5. 종료\n");
    printf("------------------\n");
    int selectMenu;
    printf("명령 입력:");
    scanf_s("%d", &selectMenu);

    switch (selectMenu) {
    case 1:
        result = add(v1, v2);
        printf("두 벡터의 합 : (%d, %d, %d)\n", result.x, result.y, result.z);
        break;
    case 2:
        result = sub(v1, v2);
        printf("두 벡터의 차 : (%d, %d, %d)\n", result.x, result.y, result.z);
        break;
    case 3:
        result = cross(v1, v2);
        printf("벡터의 외적 : (%d, %d, %d)\n", result.x, result.y, result.z);
        break;
    case 4:
        printf("벡터의 내적 : %d", dot(v1, v2));
        break;
    case 5:
        break;
    }

    return 0;
}