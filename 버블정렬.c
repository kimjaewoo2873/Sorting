#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;
void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) { // 내려가면서 n-1번 반복
		for (j = 0; j < i; j++) // 맨 오른쪽 레코드는 한 단계가 끝나고나면 정렬상태, 비교 할 필요x
			if (list[j] > list[j + 1]) // 앞 뒤 레코드 비교한 후 교체
				SWAP(list[j], list[j + 1], temp);
	}
}