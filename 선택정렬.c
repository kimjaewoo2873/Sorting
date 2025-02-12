#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) { // n-1�� -> �������� ���� ū �� �ʿ�x
		least = i;
		for (j = i + 1; j < n; j++)  // �ּҰ� Ž��
			if (list[j] < list[least])
				least = j; // �� �������� �ε��� ����
		if (i != least) // ���ʿ��ϰ� �ڱ� �ڽŰ��� �̵����� �ʰ��ϱ�����, �ּҰ��� �ڱ� �ڽ��̸� �̵����� �ʴ´�
			SWAP(list[i], list[least], temp);
	}
}

int main(void) {
	n = MAX_SIZE; 
	srand(time(NULL)); // ���� ���� �����ϱ����� �ʱ�ȭ �ڵ�
	for (int i = 0; i < n; i++) // ���� ���� �� ���
		list[i] = rand() % 100; // ���� �߻� ���� 0 ~ 99

	selection_sort(list, n);
	for (int i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
}