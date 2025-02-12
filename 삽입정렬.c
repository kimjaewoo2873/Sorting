#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) { // 0은 정렬 상태, 1부터 내려가면서 정렬
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) // j가 0보다 크거나 같고, 키 값이 비교중인 j인덱스 값보다 작아야 앞자리로 이동 가능
			list[j + 1] = list[j]; // 레코드의 오른쪽으로 이동
		list[j + 1] = key; // j는 for문 밖에서 선언했으므로 for문에서의 값 그대로 유지된다
	}
}