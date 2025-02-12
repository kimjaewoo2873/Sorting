#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

// gap만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last

void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n) { // n = sizez 
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) // 간격이 짝수면 홀수로 만들어야함
			gap++;
		for (i = 0; i < gap; i++) // 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
	}
}