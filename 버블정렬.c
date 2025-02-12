#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;
void bubble_sort(int list[], int n) {
	int i, j, temp;
	for (i = n - 1; i > 0; i--) { // �������鼭 n-1�� �ݺ�
		for (j = 0; j < i; j++) // �� ������ ���ڵ�� �� �ܰ谡 �������� ���Ļ���, �� �� �ʿ�x
			if (list[j] > list[j + 1]) // �� �� ���ڵ� ���� �� ��ü
				SWAP(list[j], list[j + 1], temp);
	}
}