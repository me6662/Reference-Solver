// 03_Priority_Queue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
/*
Priority Queue는 높은 우선순위를 가진 원소는 낮은 우선순위를 가진 원소보다 먼저 처리되는 자료구조이다.
주어진 N(2<= N <=100)개의 수를 작은 숫자가 높은 우선순위를 갖는 Priority Queue에 저장하고, 우선 순위가 높은 숫자부터 차례대로 출력하시오.
(입력에는 오류가 없다고 가정)
*/

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(int value) // 맨 꼬다리 부터 대가리로 올라감
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("Queue is full! \n");
		return 0;
	}

	heap[heapSize] = value;

	int current = heapSize;
	// (current - 1) / 2 : 부모노드

	// 부모노드가 현재노드값 보다 크면 교환 (priority 는 작은놈이기 때문)
	while (current > 0 && heap[current] < heap[(current - 1) / 2]) // [우선순위 변경 POINT!!!!!!!!!!!!!!!!!!!!!!!! > 를 < 로] 
	{
		// 부모 노드와 현재노드 값 change
		int temp = heap[(current - 1) / 2]; 
		heap[(current - 1) / 2] = heap[current]; 
		heap[current] = temp;
		
		// 부모노드 idx 를 current 로 조짐
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(int *value)
{
	// heap 에 암것도 없으면 -1
	if (heapSize <= 0)
	{
		return -1;
	}

	*value = heap[0]; // root 값 리턴
	heapSize = heapSize - 1;

	// root 값 리턴 후 트리 재정리
	// 젤 꼬다리 새끼를 대가리로 놓고
	// 대가리부터 다시 꼬다리로 내려감
	heap[0] = heap[heapSize];

	// current * 2 + 1 : 왼쪽 자식
	// current * 2 + 2 : 오른쪽 자식

	int current = 0;
	while (current * 2 + 1 < heapSize) 
	{
		int child;
		if (current * 2 + 2 == heapSize) // 오른쪽 자식 == heapsize , 즉 끝단 까지옴
		{
			child = current * 2 + 1; // 왼쪽 애랑 현재 노드랑 교환하고 끝냄. 
		}
		else // 아직 끝까지 안내려갔다면...
		{
			// 왼쪽, 오른쪽 자식중에 작은애를 부모로 올림
			child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2; // [우선순위 변경 POINT!!!!!!!!!!!!!!!!!!!!!!!! > 를 < 로] 
		}

		// 우선순위 만족할 시 break
		if (heap[current] < heap[child])// [우선순위 변경 POINT!!!!!!!!!!!!!!!!!!!!!!!! > 를 < 로] 
		{
			break;
		}

		// 자식, 부모 교환
		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return 1;
}




int main()
{
	freopen("input.txt", "r", stdin);


	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		heapInit();

		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			heapPush(value);
		}

		printf("#%d ", test_case);

		for (int i = 0; i < N; i++)
		{
			int value;
			heapPop(&value);
			printf("%d ", value);
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
