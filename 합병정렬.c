#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l; // i�� ���� ����Ʈ �ε���, j�� ������ ����Ʈ �ε���, k�� ���ĵ� ����Ʈ �ε���
	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	// mid�� �߰����̸�, ���� ������ �迭�� ũ��� ����
	// ���� �迭�� ������ٸ�, ������ �迭�� sorted�迭�� ����
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	
	// ����Ʈ �迭�� �纹��
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2; // ����Ʈ 2����
		merge_sort(list, left, mid);  // �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right); // �κ� ����Ʈ ����
		merge(list, left, mid, right); // �պ�
	}
}