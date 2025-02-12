#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) { // n-1번 -> 마지막은 가장 큰 값 필요x
		least = i;
		for (j = i + 1; j < n; j++)  // 최소값 탐색
			if (list[j] < list[least])
				least = j; // 더 작은값의 인덱스 저장
		if (i != least) // 불필요하게 자기 자신과의 이동하지 않게하기위해, 최소값이 자기 자신이면 이동하지 않는다
			SWAP(list[i], list[least], temp);
	}
}

int main(void) {
	n = MAX_SIZE; 
	srand(time(NULL)); // 랜덤 숫자 생성하기위한 초기화 코드
	for (int i = 0; i < n; i++) // 난수 생성 및 출력
		list[i] = rand() % 100; // 난수 발생 범위 0 ~ 99

	selection_sort(list, n);
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}