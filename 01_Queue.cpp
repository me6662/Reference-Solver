// 01_Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

/*
먼저 집어넣은 데이터가 먼저 나오는 FIFO 구조

- front : enqueue 하는 idx 
- rear : dequeue 하는 idx 

> data 충돌 방지를 위해서 rear 전에 한칸은 비워둔다.
> front 가 rear 바로전일때 queue 는 full 로 판단함
> front == rear 일때 empty 로 판단

*/

#define MAX_N 100 // queue 의 size 는 MAX_N-1 

int front;
int rear;
int queue[MAX_N]; // 행렬로 만든 queue

void queueInit(void) 
{
	front = 0;// enqueue 하는 idx 
	rear = 0; // dequeue 하는 idx 
}

int queueIsEmpty(void) 
{
	return (front == rear); // 같게 되면 다뺀것
}

int queueIsFull(void)
{
	if ((front + 1) % MAX_N == rear) // rear 가 front 바로 뒤면 FULL , 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(int value)
{
	if (queueIsFull())
	{
		printf("queue is full!\n");
		return 0;
	}
	
	queue[front] = value;
	front++;

	if (front == MAX_N) // 배열 5개를 다 쓰는데, rear 전에 칸은 비워둠 
	{
		front = 0; 
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty())
	{
		printf("queue is empty!\n");
		return 0;
	}
	*value = queue[rear];
	rear++;
	if (rear == MAX_N) 
	{
		rear = 0;
	}

	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	int N;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		queueInit();

		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			queueEnqueue(value);
		}

		printf("#%d ", test_case);

		while (!queueIsEmpty())
		{
			int value;

			if (queueDequeue(&value) == 1)
			{
				printf("%d ", value);
			}
			
		}
		printf("\n");		
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
