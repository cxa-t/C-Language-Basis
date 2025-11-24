#include<stdio.h>
int main()
{
	int n = 0;
	int arr[20001] = { 0 };
	scanf("%d", &n);

	int count_1 = 0, count_2 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
    int max = arr[0], min = arr[0];
    for(int i =0;i<n;i++)
    {
        if (max <= arr[i])
			max=arr[i];
		if (min >= arr[i])
			min = arr[i];
    }
    for(int i =0;i<n;i++)
    {
        if (max == arr[i])
			count_1++;
		if (min == arr[i])
			count_2++;
    }

	printf("%d %d\n", min, count_2);
	printf("%d %d", max, count_1);

	return 0;
}