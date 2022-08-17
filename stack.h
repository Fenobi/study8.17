#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDateType;

typedef struct Stack
{
	STDateType* a;
	//’ª∂•
	int top;
	int capacity;
}ST;

//≥ı ºªØ
void StackInit(ST* ps);

//œ˙ªŸ’ª
void StackDestroy(ST* ps);

//≤Â»Î
void StackPush(ST* ps,STDateType x);

//…æ≥˝
void StackPop(ST* ps);


STDateType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);