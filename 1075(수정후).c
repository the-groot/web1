#include <stdio.h>
#include <math.h>
int arr[100] = { 0 };			//가장 뒤 두자리를 저장할 배열
int third(int);
void Min(int f,int n,int i);


int main() {
	int n, f,result;
	scanf("%d", &n);
	scanf("%d", &f);	
	int i = 0;
	int N_third;		//n의 뒤에서 세번째 숫자
	N_third = third(n);

	


	while (N_third == third(n)) {		//세번째 숫자가 바뀌면 탈추

		if (n % f == 0) {			//n이 f로 나누어떨어지면
			arr[i] = n % 100;		//뒤의 두자리를 arr배열에 저장
			n = n - f;				//n을 f만큼 줄여줌
			i++;
			//printf("arr[%d]:%d\n", i, arr[i]);
		}

		else {						//n이 f로 나누어떨어지지않으면
			n = n - (n % f);		//n을 f로 나누어떨지게함
		}

		
	}

	

	if (arr[0] == 0) {		//만약 arr배열에 아무것도 저장이 안돼있으면
		n = n + f;
		arr[0] = n%100;		//최솟값을 저장해줌
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