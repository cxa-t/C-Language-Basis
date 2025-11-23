#include<stdio.h>
#include<assert.h>

char* test(char* pc,char c)
{
	assert(pc);
	while (*pc != c)
	{
		pc++;
	}
	return pc;
}

int test2(char* pc)
{
	assert(pc);
	if (*(pc - 1) == 'g'&& *(pc - 2) == 'n'&& *(pc - 3) == 'o')
		return 1;
	else
		return 0;
}

char* found(char* pc)
{
	assert(pc);
	int count = 0;
	while (count < 3)
	{
		while (*pc != ' ')
		{
			pc--;
		}
		pc--;
		count++;
	}
	pc++;
	pc++;
	return pc;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	getchar();
	char arr[111] = { 0 };
	char* first = NULL;
	char* second = NULL;
	for (int i = 0; i < a; i++)
	{
		gets(arr);
		first = test(arr,',');
		second = test(arr, '.');
		if (test2(first) == test2(second) && test2(first) == 1)
		{
			char* ptr = found(second);
			strcpy(ptr, "qiao ben zhong.");
			printf("%s\n", arr);
		}
		else
			printf("Skipped\n");
		memset(arr, 0, sizeof(arr));
		first = NULL;
		second = NULL;
	}
	return 0;
}