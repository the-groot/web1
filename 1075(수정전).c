#include <stdio.h>
#include <math.h>

int* Last_Two(int, int);
int third(int);
void Min(int[]);
void showarray(int* param) {
	for (int i = 0; i < 5; i++) {
		printf("%d\n", param[i]);
	}
}

int main() {
	int n, f, result;
	//scanf("%d", &n);
	//scanf("%d", &f);
	//int* ptr = Last_Two(n, f);
	for (int i = 0; i < 4; i++) {
		//printf("%d\n", *(ptr+i));
	}
	int arr[100] = { 1,5,7 };
	showarray(arr);

	//printf("%d %d %d\n", ptr[0], ptr[1], ptr[65]);

	//Min(ptr);

}

int* Last_Two(int n, int f) {
	int i = 0;
	int arr[100] = { 0 };	//���� �� ���ڸ��� ������ �迭
	int N_third;		//n�� �ڿ��� ����° ����
	N_third = third(n);

	while (N_third == third(n)) {		//����° ���ڰ� �ٲ�� Ż��

		if (n % f == 0) {			//n�� f�� �����������
			arr[i] = n % 100;		//���� ���ڸ��� arr�迭�� ����
			n = n - f;				//n�� f��ŭ �ٿ���
			i++;
		}

		else {						//n�� f�� �����������������
			n = n - (n % f);		//n�� f�� �����������
		}


	}
	for (int i = 0; i < 100; i++) {
		//printf("%d\n", arr[i]);
	}

	if (arr[0] == 0) {		//���� arr�迭�� �ƹ��͵� ������ �ȵ�������
		n = n + f;
		arr[0] = n;		//�ּڰ��� ��������
	}


	return arr;


}

int third(int a) {
	return ((a % 1000) - (a % 100)) / 100;
}

void Min(int* pptr) {
	int i = 1;
	int min = pptr[0];
	printf("pptr[0]:%d, min:%d\n", pptr[0], min);

	/*for (int i = 1; i < 100; i++) {
		if (min > pptr[i])
		{
			min = pptr[i];
			printf("min:%d\n", min);
		}
	}*/

	while (i < 100) {
		if (min > pptr[i]) {
			min = pptr[i];
			printf("min:%d\n", min);
		}
		i++;
	}

	if ((min / 10) == 0) {
		printf("0");
		printf("%d", min);
	}

	else
		printf("%d", min);
}