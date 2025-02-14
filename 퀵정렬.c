#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right) { // left: �����ε���, right: �������ε���
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1; // �Ʒ� do-while���̶�
	pivot = list[left]; // �ʱ� �ǹ�
	do {
		do
			low++; 
		while (list[low] < pivot); // �ǹ������� ũ�� ����
		do
			high--;
		while (list[high] > pivot); // �ǹ������� ������ ����
	} while (low < high); // low�� high�� �����ϸ� ����
	
	SWAP(list[left], list[high], temp); // �ʱ� �ǹ����� list[left]������, high ��ġ�� ��ȯ-> �ǹ� �߾� ����
	return high; // low�� high�� ���������� high���� �ǹ���
}
void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right); // �ǹ��� �ε��� ���ϱ�
		quick_sort(list, left, q - 1); // �ǹ������� �ϳ� �Ʒ�����
		quick_sort(list, q + 1, right); // �ǹ������� �ϳ� ū �� ����
	}
}