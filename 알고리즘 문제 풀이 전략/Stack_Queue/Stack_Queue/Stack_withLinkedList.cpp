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
