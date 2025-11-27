#include<stdio.h>
int test(int a)
{
	int num = 0;
	while (a > 0)
	{
		num += a % 10;
		a /= 10;
	}
	return num;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		if ((a % test(b) == 0) && (b % test(a) != 0))
			printf("A\n");
		else if ((b % test(a) == 0) && (a % test(b) != 0))
			printf("B\n");
		else if (((b % test(a) == 0) && (a % test(b) == 0)) || ((b % test(a) != 0) && (a % test(b) != 0)))
			if (a > b)
				printf("A\n");
			else
				printf("B\n");
	}
	return 0;
}
