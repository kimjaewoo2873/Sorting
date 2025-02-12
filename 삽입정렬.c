#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) { // 0�� ���� ����, 1���� �������鼭 ����
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) // j�� 0���� ũ�ų� ����, Ű ���� ������ j�ε��� ������ �۾ƾ� ���ڸ��� �̵� ����
			list[j + 1] = list[j]; // ���ڵ��� ���������� �̵�
		list[j + 1] = key; // j�� for�� �ۿ��� ���������Ƿ� for�������� �� �״�� �����ȴ�
	}
}