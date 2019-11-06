//ť - ���Ḯ��Ʈ �̿�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //��� ����
{
	int data;
	struct Node *next;
}Node;


typedef struct Queue //Queue ����ü ����
{
	Node *front; //�� ��(���� ��ġ)
	Node *rear; //�� ��(������ ��ġ)
	int count;//���� ����
}Queue;

void InitQueue(Queue *queue);//ť �ʱ�ȭ
int IsEmpty(Queue *queue); //ť�� ������� Ȯ��
void Enqueue(Queue *queue, int data); //ť�� ����
int Dequeue(Queue *queue); //ť���� ����

int main(void)
{
	int i;
	Queue queue;

	InitQueue(&queue);//ť �ʱ�ȭ
	for (i = 1; i <= 5; i++)//1~5���� ť�� ����
	{
		Enqueue(&queue, i);
	}
	while (!IsEmpty(&queue))//ť�� ������� �ʴٸ� �ݺ�
	{
		printf("%d ", Dequeue(&queue));//ť���� ������ �� ���
	}
	printf("\n");
	return 0;
}

void InitQueue(Queue *queue)
{
	queue->front = queue->rear = NULL; //front�� rear�� NULL�� ����
	queue->count = 0;//���� ������ 0���� ����
}

int IsEmpty(Queue *queue)
{
	return queue->count == 0;    //���� ������ 0�̸� �� ����
}

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