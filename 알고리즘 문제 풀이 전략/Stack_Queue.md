### Stack(스택)

- 입력과 출력을 한 방향으로 제한한 자료구조
- 바닥부터 데이터를 차곡 차곡 쌓는다.
- 푸시(Push) : 가장 위에 새로운 자료 삽입. 자료를 순서를 적용하여 차례대로 저장
- 팝(Pop) : 가장 위의 자료부터 사용(빼냄). 가장 최신 데이터부터 차례로 가져온다.
- LIFO(Last In First Out)
- 하위 자료 구조 필요. 배열/링크드 리스트

```c
#include <stdio.h>
#include <stdlib.h>

// 링크드 리스트를 사용하는 스택의 구조체 정의
// 스택의 하위 자료구조용 노드 선언
typedef struct _NODE {
	int Data;
	struct _NODE * Next;
} NODE; // 링크가 Next하나 밖에 없으므로 단일 링크드 리스트

NODE *head, *end;
NODE *ptrNode;

void InitializeStack(void); // 스택 초기화 함수
void Push(int); // 데이터 삽입
int Pop(void); // 데이터 삭제
void DisplayStack(void); // 스택을 보여줌

void InitializeStack(void) {
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));
	head->Next = end;
	end->Next = end;
}

void Push(int num) { // int num: 스택에 저장될 데이터
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;
	ptrNode->Next = head->Next;
	head->Next = ptrNode; // 순서 중요
}

int Pop(void) {
	int ret;
	ptrNode = head->Next;
	head->Next = head->Next->Next;
	ret = ptrNode->Data;
	free(ptrNode);

	return ret; // 현재 스택에 저장되어 있는 최상위 값
}

void DisplayStack(void) {
	NODE *indexNode;
	printf("head -> ");

	for (indexNode = head->Next; indexNode != end; indexNode = indexNode->Next) {
		printf("%d -> ", indexNode->Data);
	}
	printf("end");
}

void main() {
	int ret;
	InitializeStack();

	Push(1);
	Push(3);
	Push(78);
	Push(412156);
	Push(47445);
	
	printf("다섯 번의 Push() 함수 호출 후 실행 결과\n");
	DisplayStack();

	ret = Pop();
	ret = Pop();
	ret = Pop();

	printf("\n세 번의 Pop() 함수 호출 후 실행 결과\n");
	DisplayStack();

}
```



### Queue

- 큐를 사용하는 대표적인 소프트웨어는 윈도우, 리눅스 등 운영체제
- FIFO(First In First Out)
- Put : 도착하는 차례대로 데이터를 저장
- Get : 처음 저장한 데이터부터 차례로 사용
- 하위 자료구조 필요. 배열, 링크드 리스트(배열 사용이 조금 더 편리)

```c
#include <stdio.h>
#define MAX 100

// 큐 선언
int Queue[MAX];
int Front, Rear;

void InitializeQueue(void); // 큐 초기화 함수
void Put(int); // 데이터 삽입
int Get(void); // 데이터 삭제
void DisplayQueue(void); // 큐를 보여줌

void InitializeQueue(void) {
	Front = Rear = 0;
}

void Put(int num) {
	Queue[Rear++] = num;

	if (Rear >= MAX) Rear = 0;
}

int Get(void) {
	int ret;
	ret = Queue[Front++];

	if (Front >= MAX) Front = 0;

	return ret;
}

void DisplayQueue(void) {
	int i;
	printf("Front -> ");

	for (i = Front; i < Rear; i++) {
		printf("%2d -> ", Queue[i]);
	}

	printf("Rear");
}

void main() {
	int ret;
	InitializeQueue();

	Put(1);
	Put(3);
	Put(10);
	Put(20);
	Put(12);

	printf("다섯 번의 Put() 함수 호출 후 결과\n");
	DisplayQueue();

	ret = Get();
	ret = Get();
	ret = Get();

	printf("\n세 번의 Get() 함수 호출 후 결과\n");
	DisplayQueue();

	printf("\n두 번의 Get() 함수 호출 후 결과\n");

	ret = Get();
	ret = Get();
	DisplayQueue();
}
```

