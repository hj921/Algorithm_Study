#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *Next;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);

void Initialize(void) {
	NODE *ptr;
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));

	temp1 = (NODE *)malloc(sizeof(NODE));
	temp1->Data = 'A';
	head->Next = temp1;
	temp1->Next = end;
	end->Next = end;
	ptr = temp1;

	temp2 = (NODE *)malloc(sizeof(NODE));
	temp2->Data = 'B';
	ptr->Next = temp2;
	temp2->Next = end;
	ptr = temp2;

	temp3 = (NODE *)malloc(sizeof(NODE));
	temp3->Data = 'D';
	ptr->Next = temp3;
	temp3->Next = end;
	ptr = temp3;

	temp4 = (NODE *)malloc(sizeof(NODE));
	temp4->Data = 'E';
	ptr->Next = temp4;
	temp4->Next = end;
	ptr = temp4;
}

void InsertNode(NODE *ptr) {
	NODE *indexptr;

	for (indexptr = head; indexptr != end; indexptr = indexptr->Next) {
		if (indexptr->Next->Data > ptr->Data) {
			break;
		}
	}

	ptr->Next = indexptr->Next;
	indexptr->Next = ptr;

}

void DeleteNode(NODE *ptr) {
	NODE *indexptr;
	NODE *deleteptr;

	// 삭제할 노드를 검색하는 부분
	for (indexptr = head; indexptr != end; indexptr = indexptr->Next) {
		if (indexptr->Next->Data == ptr->Data) {
			deleteptr = indexptr->Next;
			break;
		}
	}

	// 노드를 실제로 삭제하는 부분
	indexptr->Next = indexptr->Next->Next;
	free(deleteptr); // free: 힙 영역에 할당된 메모리를 해제하는 함수 <- malloc()함수를 사용하여 동적할당 하였으므로 free를 이용하여 해제
}



void main() {
	NODE *ptr;
	int i = 0;
	Initialize();

	// 링크드 리스트의 노드에 저장한 데이터 출력
	printf("노드 C의 삽입 전\n");
	ptr = head->Next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");

	// 삽입할 새로운 노드 생성
	temp = (NODE *)malloc(sizeof(NODE));
	temp->Data = 'C';

	// 새로 생성한 노드 삽입
	InsertNode(temp);
	
	// 링크드 리스트의 노드에 저장한 데이터 출력
	printf("노드 C의 삽입 후\n");
	ptr = head->Next;

	for (i = 0; i < 5; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");

	// 노드의 삭제
	DeleteNode(temp);

	// 링크드 리스트의 노드에 저장된 데이터 출력
	printf("n노드 C의 삭제 후\n");
	ptr = head->Next;

	for (i = 0; i < 4; i++) {
		printf("%2c", ptr->Data);
		ptr = ptr->Next;
	}
	printf("\n");

}