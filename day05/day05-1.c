#include <stdio.h>
#include <stdlib.h>

void main() {
    int numOfStudents;
    printf("Enter Number of Students : ");
    scanf_s("%d", &numOfStudents);

    int *studentID = (int*)malloc(sizeof(int) * numOfStudents);
    char (*studentName)[50] = (char(*)[50])malloc(sizeof(char) * 50 * numOfStudents);
    int *studentScore = (int*)malloc(sizeof(int) * numOfStudents);

    for (int i = 0; i < numOfStudents; i++) {
        printf("Student %d's ID, Name, Score:", i + 1);
        scanf("%d %s %d", &studentID[i], &studentName[i], &studentScore[i]);
    }

    float maxScore = studentScore[0], minScore = studentScore[0], avgScore = 0, tmp = 0;
    for (int i=0; i<numOfStudents; i++) {
        if (studentScore[i] > maxScore) {
            maxScore = studentScore[i];
        }
        if (studentScore[i] < minScore) {
            minScore = studentScore[i];
        }
        tmp += studentScore[i];
    }
    avgScore = tmp / numOfStudents;

    printf("maxScore : %.2f\n",maxScore);
    printf("minScore : %.2f\n",minScore);
    printf("avgScore : %.2f\n",avgScore);

    free(studentID); free(studentName); free(studentScore);
}
