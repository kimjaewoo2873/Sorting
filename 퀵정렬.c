#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right) { // left: 시작인덱스, right: 마지막인덱스
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; // 아래 do-while문이라서
	pivot = list[left]; // 초기 피벗
	do {
		do
			low++; 
		while (list[low] < pivot); // 피벗값보다 크면 멈춤
		do
			high--;
		while (list[high] > pivot); // 피벗값보다 작으면 멈춤
	} while (low < high); // low와 high가 교차하면 종료
	
	SWAP(list[left], list[high], temp); // 초기 피벗값이 list[left]였으니, high 위치와 교환-> 피벗 중앙 정렬
	return high; // low와 high가 교차됐을때 high값이 피벗값
}
void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right); // 피벗값 인덱스 구하기
		quick_sort(list, left, q - 1); // 피벗값보다 하나 아래까지
		quick_sort(list, q + 1, right); // 피벗값보다 하나 큰 것 부터
	}
}