#define _CRT_SECURE_NO_WARNINGS

#include "stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->top = 0;//top=-1
	ps->a = NULL;

}

void StackDestroy(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;

}
void StackPush(ST* ps, STDateType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDateType* tmp = realloc(ps->a, sizeof(STDateType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;

	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps->top > 0);
	assert(ps);

	ps->top--;
}
STDateType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}