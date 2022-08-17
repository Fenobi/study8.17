#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDateType;

typedef struct Stack
{
	STDateType* a;
	//ջ��
	int top;
	int capacity;
}ST;

//��ʼ��
void StackInit(ST* ps);

//����ջ
void StackDestroy(ST* ps);

//����
void StackPush(ST* ps,STDateType x);

//ɾ��
void StackPop(ST* ps);


STDateType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);