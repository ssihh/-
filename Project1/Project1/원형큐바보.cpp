#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h>

typedef struct Node {
	int data;	//���ڵ�����
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
		printf("�����");
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
	for (i = 1; i <= 5; i++)//1~5���� ť�� ����
	{
		Enqu(&qu, i);
	}
	while (!isEmpty(&qu))//ť�� ������� �ʴٸ� �ݺ�
	{
		printf("%d ", Dequ(&qu));//ť���� ������ �� ���
	}

	return 0;
}
/*
void Enqueue(Queue *queue, int data)
{
	Node *now = (Node *)malloc(sizeof(Node)); //��� ����
	now->data = data;//������ ����
	now->next = NULL;

	if (IsEmpty(queue))//ť�� ������� ��
	{
		queue->front = now;//�� ���� now�� ����       
	}
	else//������� ���� ��
	{
		queue->rear->next = now;//�� ���� ������ now�� ����
	}
	queue->rear = now;//�� �ڸ� now�� ����   
	queue->count++;//���� ������ 1 ����
}

int Dequeue(Queue *queue)
{
	int re = 0;
	Node *now;
	if (IsEmpty(queue))//ť�� ����� ��
	{
		return re;
	}
	now = queue->front;//�� ���� ��带 now�� ���
	re = now->data;//��ȯ�� ���� now�� data�� ����
	queue->front = now->next;//�� ���� now�� ���� ���� ����
	free(now);//now �Ҹ�
	queue->count--;//���� ������ 1 ����
	return re;
}
*/