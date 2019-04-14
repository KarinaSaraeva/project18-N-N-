#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
#include <stdlib.h>
int flag;

void replace(int *pX,int *pY) {
	int temp;
	temp = *pX;
	*pX = *pY;
	*pY = temp;
}
void compare(int *pX, int *pY) {
	if (*pX > *pY) { replace(pX, pY); flag = 1; }
}

void compareDOWN(int *pX, int *pY) {
	if (*pX < *pY) { replace(pX, pY); flag = 1; };
}

void compareABSOLUT_VALUE(int *pX, int *pY) {
	if (abs(*pX) < abs(*pY)) { replace(pX, pY); flag = 1; };
}

void output_array(int *pArr, int N) {
	for (int i = 0; i < N; ++i)
		printf("%3d", *(pArr + i));
	printf("\n");
}
int main() {
	int N;
	printf("Input elements count: ");
	scanf_s("%d", &N);
	printf("enter data\n");
	int *pArr = (int *)malloc(sizeof(int)*N);
	if (pArr == NULL)
	{
		printf("Can’t allocate memory!");
	}
	for (int i = 0; i < N; i++)
		scanf_s("%d", (pArr + i));
	replace(&*(pArr), &*(pArr + 1));
	output_array(pArr, N);

	void(*operations[3])(int, int) = { compare, compareDOWN, compareABSOLUTE_VALUE };


	printf("choose an algorithm of array sorting\n 1-UP\n 2-DOWN\n 3-ABSOLUTE_VALUE\n");
	int answer=0;
	scanf_s("%d", &answer);
	for (int i = 0; i < N - 1; i++) {
		int j_min = i;
		for (int j = i + 1; j < N; j++) {
			
				j_min = j;
			}
		}
	output_array(pArr, N);
	_getch();

	return 0;
	}
			