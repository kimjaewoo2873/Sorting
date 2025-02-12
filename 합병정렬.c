#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l; // i는 왼쪽 리스트 인덱스, j는 오른쪽 리스트 인덱스, k는 정렬될 리스트 인덱스
	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// mid는 중간값이며, 왼쪽 오른쪽 배열의 크기와 같음
	// 한쪽 배열이 비워졌다면, 나머지 배열을 sorted배열에 삽입
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	
	// 리스트 배열로 재복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; // 리스트 2분할
		merge_sort(list, left, mid);  // 부분 리스트 정렬
		merge_sort(list, mid + 1, right); // 부분 리스트 정렬
		merge(list, left, mid, right); // 합병
	}
}