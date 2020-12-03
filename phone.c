#include <stdio.h>
#include <string.h>
#define SIZE 20			//전화번호부의 용량 바꿀수있음
	
typedef struct PHONE {		//전화번호 구조체. 이름과 전화번호를 입력받음
	char name[SIZE];
	char num[SIZE];

}phone;


int LoadFile(phone* call);				//파일로부터 전화번호부 정보를 불러오는 함수
void SaveFile(phone *call, int);		//파일에다가 전화번호부 정보를 저장하는 함수
void ShowMenu();						//선택메뉴출력함수
void Insert(phone *call,int,int );		//정보 입력 함수
void Delete(phone* call);				//정보 삭제 함수
void Search(phone*);					//정보 탐색 함수
void PrintAll(phone*, int,int);			//전화번호부 전체 출력 함수

void main() {
	int choose;		//menu선택 변수
	phone call[SIZE] = { NULL };	//이름과 번호를 담을 배열 처음에 공백으로 초기화해줌
	int cnt1 = 0;				//insert가 몇번됐는지 저장하는 변수
	int cnt2;					//file에 저장된 name&num의 개수
	cnt2=LoadFile(call);		//파일 읽어들임
	cnt1 = cnt2;				//file에 저장된게 0개면 insert도 0개된것 만약 cnt2만큼 file에 저장돼있으면 insert는 [cnt2] index이후로 이루어져야함
	
	
	
	while (1) {			//20개를 다 입력하거나 5번을 누를때까지 무한반복
		ShowMenu();		//menu보여줌
		scanf("%d", &choose);	//몇번 선택할건지 입력받음
		getchar();		//공백지워줌
		if (choose == 1) {		
			Insert(call,cnt1,cnt2);
			cnt1++;				//1번선택할때마다 cnt1을 1씩추가함 cnt1은 call[]의 index가 될것임
			if (cnt1 == SIZE)		//용량 초과하면 탈출
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
			printf("다시입력하세요\n");
		}

	}

	
	
}

int LoadFile(phone call[SIZE]) {			//파일을 불러오는 함수
	int i = 0;								//call[index]가 몇까지 저장돼있는지 세는 변수
	FILE* fp = fopen("phone.txt", "rt");	

	if (fp == NULL) {
		printf("파일 오픈 실패\n");
		return -1;
	}

	else {

		for (i; i < SIZE; i++) {						//배열의 크기만큼 반복
			printf("%d번쨰\n", i);
			fscanf(fp, "%s", call[i].name);				//fscanf는 스페이스,엔터를 별도의 데이터로 간주한다
			fscanf(fp, "%s", call[i].num);				//그리고 fscanf는 비공백문자를 읽어들이기 전까지 읽혀지는 모든 공백문자들을 무시한다
														//따라서 delete에 의해 공백 문자가 중간에 껴있어도 무시하고
														//비공백문자가 나올때 그걸 배열에 저장하고 스페이스로 구분해 이름과 전화번호를 저장한다

			/*fgets(call[i].name, SIZE, fp);			//fgets는 엔터만이 데이터를 구분해준다
			fgets(call[i].num, SIZE, fp);*/				//따라서 공백이건 스페이스건 모두 읽어들인다 여기서는 fgets가 쓰이기 적합하지않다.

			printf("%s\n", call[0].name);
			if (strcmp(call[i].name, "") ==0){		//fscanf가 공백을 무시하고 받아들인후에
				break;							//있는 공백은 입력되지않은것이므로 여기까지 받아들이고 탈출한다
			}
			
		}
	}
	
	fclose(fp);
	return i;				//i는 파일에 call[index]가 몇까지 있는지 반환해준다 그리고 i이후부터 insert하게한다(정보가 손상되지않게하기위해서)
}

void SaveFile(phone call[SIZE],int n) {	//파일에 정보를 저장하는 함수
	FILE* fp = fopen("phone.txt", "wt");
	
	if (fp == NULL) {
		printf("파일 오픈 실패\n");
		return -1;
	}
	else {

		for (int i = 0; i < n; i++) {		//입력된 index까지만
			fprintf(fp, "%s %s\n", call[i].name, call[i].num);	//Delete에 의해 생긴 공백이 있어도 상관없으니 파일에 저장한다
		}														//공백은 LoadFile의 fscanf에 의해 무시당할것이니 상관없다
	}
	fclose(fp);

}

void ShowMenu() {		//메뉴보여주는 함수
	

	fputs("*****MENU*****\n", stdout);
	fputs("1. Insert\n",stdout);
	fputs("2. Delete\n", stdout);
	fputs("3. Search\n", stdout);
	fputs("4. Print All\n", stdout);
	fputs("5. Exit\n", stdout);
	printf("Choose the item: ");


}

void Insert(phone call[SIZE],int cnt1,int cnt2) {	//값 입력받는 함수
	printf("[ INSERT ]\n");
	printf("Input Name: ");
	scanf("%s", call[cnt1].name);	//cnt1부터 이름 입력받음
	getchar();		//공백제거
	printf("Input Tel Number: ");
	scanf("%s", call[cnt1].num);	//cnt1부터 num 입력받고
	getchar();	//공백제거
	

	printf("           Data Inserted\n");


}

void Delete(phone call[SIZE]) {		//정보 삭제하는 함수
	phone delete;	//삭제할 이름찾기위한 변수
	int i = 0;	
	int j = 0;			//call.name의 값을 0부터 초기화하기위한 변수
	int k = 0;			//call.num의  값을 0부터 초기화하기위한 변수
	printf("[ Delete ]\n");
	printf("Input Name: ");
	scanf("%s", delete.name);	//삭제할 이름 입력
	getchar();					//공백제거
	
	while (1) {
		if (strcmp(call[i].name, delete.name) == 0) {	//반복문을 돌며 삭제할이름이 call.name과 일치할때
			while (call[i].name[j] != NULL) {//문자열의 끝까지
				call[i].name[j] = 0;		//공백처리함
				j++;
			}
			while (call[i].num[k] != NULL) {	//마찬가지로 문자열의 끝까지
				call[i].num[k] = 0;				//공백처리함
				k++;
			}
			printf("           Data deleted\n");	//다 공백처리했으면
			break;	//반복문 탈출
		}

		else if (i == SIZE) {		//i가 20이될때까지 반복문을 돌아도
									//이름을 못찾았으면
			printf("           Data didn't deleted\n");	//삭제되지않음 출력
			break;
		}
		i++;
	}
	
	

}

void Search(phone call[SIZE]) {	//이름을 입력해 정보 출력하는 함수
	phone search;		//찾고싶은 정보의 이름을 입력받는 변수
	int i = 0;

	printf("[ SEARCH ]\n");
	printf("Input Name: ");
	scanf("%s", search.name);		//이름 입력받음
	getchar();		//공백제거
	
	while (1) {
	
		if (strcmp(call[i].name, search.name) == 0) {	//반복문을 돌며 일치하는 이름을 찾았을때
			printf("이름:[%s]   전화번호:[%s]\n", call[i].name,call[i].num);	//정보 출력
			break;
		}
		else if(i==SIZE) {
			printf("검색 결과가 없습니다.\n");	//i가 20이될때까지도 찾지못했을때 출력
			break;
		}


			i++;
	}

}

void PrintAll(phone call[SIZE], int cnt1,int cnt2) {	//전화번호부 전체 출력
	int i = 0;
	printf("[ Print All Data ]\n");

	




		for (i; i < SIZE; i++) {		//SIZE까지 돌면서
			if (strcmp(call[i].name, "") == 0) {	//만약 삭제에 의해 생긴 공백 혹은 아직 입력받지 않은 값의 공백
				continue;							//이 있다면 출력하지말고 반복문을 continue할것
			}
			printf("이름: [%s]   전화번호: [%s]\n", call[i].name, call[i].num);	//공백이 없다면 정보 순서대로 출력할것

		}
	}
