#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>

typedef struct Node {
	int data;	//숫자데이터
	struct Node *next;
}Node;

typedef struct Q {
	Node *rear;
}Q;

void initQ(Q *qu) {
	qu->rear = NULL;
}

int isEmpty(Q *qu) {
	return qu->rear == NULL;
}

void Enqu(Q *qu, int data) {
	Node *newq = (Node *)malloc(sizeof(Node));
	newq->data = data;
	newq->next = NULL;
	if (isEmpty(qu)) {
		qu->rear = newq;
	}
	else {
		newq->next = qu->rear->next;
		qu->rear->next = newq;

	}
	
	newq->next = qu->rear;
	qu->rear = newq;
}

int Dequ(Q *qu) {
	int dedata=0;
	Node *bye;
	if (isEmpty(qu)) {
		printf("비엇엉");
		return dedata;
	}
	else {
		bye = qu->rear->next;
		dedata = bye->data;
		qu->rear->next = bye->next;
		free(bye);
	}
	return dedata;
}

int main() {
	int i;
	Q qu;
	initQ(&qu);
	for (i = 1; i <= 5; i++)//1~5까지 큐에 보관
	{
		Enqu(&qu, i);
	}
	while (!isEmpty(&qu))//큐가 비어있지 않다면 반복
	{
		printf("%d ", Dequ(&qu));//큐에서 꺼내온 값 출력
	}

	return 0;
}
/*
void Enqueue(Queue *queue, int data)
{
	Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
	now->data = data;//데이터 설정
	now->next = NULL;

	if (IsEmpty(queue))//큐가 비어있을 때
	{
		queue->front = now;//맨 앞을 now로 설정       
	}
	else//비어있지 않을 때
	{
		queue->rear->next = now;//맨 뒤의 다음을 now로 설정
	}
	queue->rear = now;//맨 뒤를 now로 설정   
	queue->count++;//보관 개수를 1 증가
}

int Dequeue(Queue *queue)
{
	int re = 0;
	Node *now;
	if (IsEmpty(queue))//큐가 비었을 때
	{
		return re;
	}
	now = queue->front;//맨 앞의 노드를 now에 기억
	re = now->data;//반환할 값은 now의 data로 설정
	queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
	free(now);//now 소멸
	queue->count--;//보관 개수를 1 감소
	return re;
}
*/