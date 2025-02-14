#include <stdio.h>
#include <stdlib.h>

int compare(const void* arg1, const void* arg2) {
	if (*(double*)arg1 > *(double*)arg2) 
		return 1;
	else if (*(double*)arg1 == *(double*)arg2) 
		return 0;
	else 
		return -1;
}
int main(void) {
	int i;
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };
	qsort((void*)list, (size_t)5, sizeof(double), compare); // 배열의 시작주소, 요소의 개수, 요소 하나의 크기(바이트 단위)
	for (i = 0; i < 5; i++)
		printf("%f ", list[i]);
}