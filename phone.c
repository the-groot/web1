#include <stdio.h>
#include <string.h>
#define SIZE 20			//��ȭ��ȣ���� �뷮 �ٲܼ�����
	
typedef struct PHONE {		//��ȭ��ȣ ����ü. �̸��� ��ȭ��ȣ�� �Է¹���
	char name[SIZE];
	char num[SIZE];

}phone;


int LoadFile(phone* call);				//���Ϸκ��� ��ȭ��ȣ�� ������ �ҷ����� �Լ�
void SaveFile(phone *call, int);		//���Ͽ��ٰ� ��ȭ��ȣ�� ������ �����ϴ� �Լ�
void ShowMenu();						//���ø޴�����Լ�
void Insert(phone *call,int,int );		//���� �Է� �Լ�
void Delete(phone* call);				//���� ���� �Լ�
void Search(phone*);					//���� Ž�� �Լ�
void PrintAll(phone*, int,int);			//��ȭ��ȣ�� ��ü ��� �Լ�

void main() {
	int choose;		//menu���� ����
	phone call[SIZE] = { NULL };	//�̸��� ��ȣ�� ���� �迭 ó���� �������� �ʱ�ȭ����
	int cnt1 = 0;				//insert�� ����ƴ��� �����ϴ� ����
	int cnt2;					//file�� ����� name&num�� ����
	cnt2=LoadFile(call);		//���� �о����
	cnt1 = cnt2;				//file�� ����Ȱ� 0���� insert�� 0���Ȱ� ���� cnt2��ŭ file�� ����������� insert�� [cnt2] index���ķ� �̷��������
	
	
	
	while (1) {			//20���� �� �Է��ϰų� 5���� ���������� ���ѹݺ�
		ShowMenu();		//menu������
		scanf("%d", &choose);	//��� �����Ұ��� �Է¹���
		getchar();		//����������
		if (choose == 1) {		
			Insert(call,cnt1,cnt2);
			cnt1++;				//1�������Ҷ����� cnt1�� 1���߰��� cnt1�� call[]�� index�� �ɰ���
			if (cnt1 == SIZE)		//�뷮 �ʰ��ϸ� Ż��
				break;
			
		}
		

		else if (choose == 2) {
			Delete(call);
		}

		else if (choose == 3) {
			Search(call);
		}
		else if (choose == 4) {
			PrintAll(call,cnt1,cnt2); 
		}


		else if (choose == 5) {
			SaveFile(call,cnt1);
			break;
		}

		else
		{	
			printf("�ٽ��Է��ϼ���\n");
		}

	}

	
	
}

int LoadFile(phone call[SIZE]) {			//������ �ҷ����� �Լ�
	int i = 0;								//call[index]�� ����� ������ִ��� ���� ����
	FILE* fp = fopen("phone.txt", "rt");	

	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}

	else {

		for (i; i < SIZE; i++) {						//�迭�� ũ�⸸ŭ �ݺ�
			printf("%d����\n", i);
			fscanf(fp, "%s", call[i].name);				//fscanf�� �����̽�,���͸� ������ �����ͷ� �����Ѵ�
			fscanf(fp, "%s", call[i].num);				//�׸��� fscanf�� ����鹮�ڸ� �о���̱� ������ �������� ��� ���鹮�ڵ��� �����Ѵ�
														//���� delete�� ���� ���� ���ڰ� �߰��� ���־ �����ϰ�
														//����鹮�ڰ� ���ö� �װ� �迭�� �����ϰ� �����̽��� ������ �̸��� ��ȭ��ȣ�� �����Ѵ�

			/*fgets(call[i].name, SIZE, fp);			//fgets�� ���͸��� �����͸� �������ش�
			fgets(call[i].num, SIZE, fp);*/				//���� �����̰� �����̽��� ��� �о���δ� ���⼭�� fgets�� ���̱� ���������ʴ�.

			printf("%s\n", call[0].name);
			if (strcmp(call[i].name, "") ==0){		//fscanf�� ������ �����ϰ� �޾Ƶ����Ŀ�
				break;							//�ִ� ������ �Էµ����������̹Ƿ� ������� �޾Ƶ��̰� Ż���Ѵ�
			}
			
		}
	}
	
	fclose(fp);
	return i;				//i�� ���Ͽ� call[index]�� ����� �ִ��� ��ȯ���ش� �׸��� i���ĺ��� insert�ϰ��Ѵ�(������ �ջ�����ʰ��ϱ����ؼ�)
}

void SaveFile(phone call[SIZE],int n) {	//���Ͽ� ������ �����ϴ� �Լ�
	FILE* fp = fopen("phone.txt", "wt");
	
	if (fp == NULL) {
		printf("���� ���� ����\n");
		return -1;
	}
	else {

		for (int i = 0; i < n; i++) {		//�Էµ� index������
			fprintf(fp, "%s %s\n", call[i].name, call[i].num);	//Delete�� ���� ���� ������ �־ ��������� ���Ͽ� �����Ѵ�
		}														//������ LoadFile�� fscanf�� ���� ���ô��Ұ��̴� �������
	}
	fclose(fp);

}

void ShowMenu() {		//�޴������ִ� �Լ�
	

	fputs("*****MENU*****\n", stdout);
	fputs("1. Insert\n",stdout);
	fputs("2. Delete\n", stdout);
	fputs("3. Search\n", stdout);
	fputs("4. Print All\n", stdout);
	fputs("5. Exit\n", stdout);
	printf("Choose the item: ");


}

void Insert(phone call[SIZE],int cnt1,int cnt2) {	//�� �Է¹޴� �Լ�
	printf("[ INSERT ]\n");
	printf("Input Name: ");
	scanf("%s", call[cnt1].name);	//cnt1���� �̸� �Է¹���
	getchar();		//��������
	printf("Input Tel Number: ");
	scanf("%s", call[cnt1].num);	//cnt1���� num �Է¹ް�
	getchar();	//��������
	

	printf("           Data Inserted\n");


}

void Delete(phone call[SIZE]) {		//���� �����ϴ� �Լ�
	phone delete;	//������ �̸�ã������ ����
	int i = 0;	
	int j = 0;			//call.name�� ���� 0���� �ʱ�ȭ�ϱ����� ����
	int k = 0;			//call.num��  ���� 0���� �ʱ�ȭ�ϱ����� ����
	printf("[ Delete ]\n");
	printf("Input Name: ");
	scanf("%s", delete.name);	//������ �̸� �Է�
	getchar();					//��������
	
	while (1) {
		if (strcmp(call[i].name, delete.name) == 0) {	//�ݺ����� ���� �������̸��� call.name�� ��ġ�Ҷ�
			while (call[i].name[j] != NULL) {//���ڿ��� ������
				call[i].name[j] = 0;		//����ó����
				j++;
			}
			while (call[i].num[k] != NULL) {	//���������� ���ڿ��� ������
				call[i].num[k] = 0;				//����ó����
				k++;
			}
			printf("           Data deleted\n");	//�� ����ó��������
			break;	//�ݺ��� Ż��
		}

		else if (i == SIZE) {		//i�� 20�̵ɶ����� �ݺ����� ���Ƶ�
									//�̸��� ��ã������
			printf("           Data didn't deleted\n");	//������������ ���
			break;
		}
		i++;
	}
	
	

}

void Search(phone call[SIZE]) {	//�̸��� �Է��� ���� ����ϴ� �Լ�
	phone search;		//ã����� ������ �̸��� �Է¹޴� ����
	int i = 0;

	printf("[ SEARCH ]\n");
	printf("Input Name: ");
	scanf("%s", search.name);		//�̸� �Է¹���
	getchar();		//��������
	
	while (1) {
	
		if (strcmp(call[i].name, search.name) == 0) {	//�ݺ����� ���� ��ġ�ϴ� �̸��� ã������
			printf("�̸�:[%s]   ��ȭ��ȣ:[%s]\n", call[i].name,call[i].num);	//���� ���
			break;
		}
		else if(i==SIZE) {
			printf("�˻� ����� �����ϴ�.\n");	//i�� 20�̵ɶ������� ã���������� ���
			break;
		}


			i++;
	}

}

void PrintAll(phone call[SIZE], int cnt1,int cnt2) {	//��ȭ��ȣ�� ��ü ���
	int i = 0;
	printf("[ Print All Data ]\n");

	




		for (i; i < SIZE; i++) {		//SIZE���� ���鼭
			if (strcmp(call[i].name, "") == 0) {	//���� ������ ���� ���� ���� Ȥ�� ���� �Է¹��� ���� ���� ����
				continue;							//�� �ִٸ� ����������� �ݺ����� continue�Ұ�
			}
			printf("�̸�: [%s]   ��ȭ��ȣ: [%s]\n", call[i].name, call[i].num);	//������ ���ٸ� ���� ������� ����Ұ�

		}
	}
