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
	int arr[100] = { 0 };	//가장 뒤 두자리를 저장할 배열
	int N_third;		//n의 뒤에서 세번째 숫자
	N_third = third(n);

	while (N_third == third(n)) {		//세번째 숫자가 바뀌면 탈추

		if (n % f == 0) {			//n이 f로 나누어떨어지면
			arr[i] = n % 100;		//뒤의 두자리를 arr배열에 저장
			n = n - f;				//n을 f만큼 줄여줌
			i++;
		}

		else {						//n이 f로 나누어떨어지지않으면
			n = n - (n % f);		//n을 f로 나누어떨지게함
		}


	}
	for (int i = 0; i < 100; i++) {
		//printf("%d\n", arr[i]);
	}

	if (arr[0] == 0) {		//만약 arr배열에 아무것도 저장이 안돼있으면
		n = n + f;
		arr[0] = n;		//최솟값을 저장해줌
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