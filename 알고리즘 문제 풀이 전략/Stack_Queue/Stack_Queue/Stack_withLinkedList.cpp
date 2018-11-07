#include <stdio.h>
#include <stdlib.h>

// ��ũ�� ����Ʈ�� ����ϴ� ������ ����ü ����
// ������ ���� �ڷᱸ���� ��� ����
typedef struct _NODE {
	int Data;
	struct _NODE * Next;
} NODE; // ��ũ�� Next�ϳ� �ۿ� �����Ƿ� ���� ��ũ�� ����Ʈ

NODE *head, *end;
NODE *ptrNode;

void InitializeStack(void); // ���� �ʱ�ȭ �Լ�
void Push(int); // ������ ����
int Pop(void); // ������ ����
void DisplayStack(void); // ������ ������

void InitializeStack(void) {
	head = (NODE *)malloc(sizeof(NODE));
	end = (NODE *)malloc(sizeof(NODE));
	head->Next = end;
	end->Next = end;
}

void Push(int num) { // int num: ���ÿ� ����� ������
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;
	ptrNode->Next = head->Next;
	head->Next = ptrNode; // ���� �߿�
}

int Pop(void) {
	int ret;
	ptrNode = head->Next;
	head->Next = head->Next->Next;
	ret = ptrNode->Data;
	free(ptrNode);

	return ret; // ���� ���ÿ� ����Ǿ� �ִ� �ֻ��� ��
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
	
	printf("�ټ� ���� Push() �Լ� ȣ�� �� ���� ���\n");
	DisplayStack();

	ret = Pop();
	ret = Pop();
	ret = Pop();

	printf("\n�� ���� Pop() �Լ� ȣ�� �� ���� ���\n");
	DisplayStack();

}
