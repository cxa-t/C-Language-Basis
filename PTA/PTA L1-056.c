#include<stdio.h>
#include<string.h>

struct M
{
	char name[11];
	int guess;
};

int main()
{
	struct M m[10001];
	int num = 0;
	scanf("%d", &num);
	int guess_total = 0;
	for (int i = 0; i < num; i++)
	{
		scanf("%s %d", &m[i].name, &m[i].guess);
		guess_total += m[i].guess;
	}
	int average = guess_total / (num * 2);

	int min_guess = 101;
	char min_name[11];
	for (int i = 0; i < num; i++)
	{
		m[i].guess -= average;
		if (m[i].guess < 0)
			m[i].guess *= (-1);
		if (m[i].guess < min_guess)
		{
			min_guess = m[i].guess;
			strcpy(min_name, m[i].name);
		}
	}

	printf("%d %s", average,min_name);
	return 0;
}