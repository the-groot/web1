#include <stdio.h>
#include <math.h>
int arr[100] = { 0 };			//���� �� ���ڸ��� ������ �迭
int third(int);
void Min(int f,int n,int i);


int main() {
	int n, f,result;
	scanf("%d", &n);
	scanf("%d", &f);	
	int i = 0;
	int N_third;		//n�� �ڿ��� ����° ����
	N_third = third(n);

	


	while (N_third == third(n)) {		//����° ���ڰ� �ٲ�� Ż��

		if (n % f == 0) {			//n�� f�� �����������
			arr[i] = n % 100;		//���� ���ڸ��� arr�迭�� ����
			n = n - f;				//n�� f��ŭ �ٿ���
			i++;
			//printf("arr[%d]:%d\n", i, arr[i]);
		}

		else {						//n�� f�� �����������������
			n = n - (n % f);		//n�� f�� �����������
		}

		
	}

	

	if (arr[0] == 0) {		//���� arr�迭�� �ƹ��͵� ������ �ȵ�������
		n = n + f;
		arr[0] = n%100;		//�ּڰ��� ��������
	}

	Min(f,n,i);
	
}


int third(int a) {
	return ((a % 1000) - (a % 100)) / 100;
}

void Min(int f,int n,int i) {
	int j = 1;
	int min=arr[0];
	while (j < i) {
		if (min > arr[j]) {
			min = arr[j];
		}
		j++;
	}
	


	if ((min / 10) == 0) {
		printf("0");
		printf("%d", min);
	}

	else
		printf("%d", min);
}