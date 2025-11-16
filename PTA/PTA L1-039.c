#include<stdio.h>
#include<string.h>
int main()
{
    char arr[1010];
    int row = 0;
    scanf("%d", &row);
    getchar();
    gets(arr);
    int len = strlen(arr);
    
    int lie = 0;
    if (len % row == 0)
        lie = len / row;
    else
        lie = (len / row) + 1;
    int k = 0;
    char brr[1001][1001];
    for (int j = lie - 1; j >= 0; j--)//4 3 2 1 0
    {
        for (int i = 0; i < row; i++)//0 1 2 3
        {
            if (arr[k] != '\0')
                brr[i][j] = arr[k++];
            else
                brr[i][j] = ' ';
        }
    }

    for (int i = 0; i < row; i++)//0 1 2 3
    {
        for (int j = 0; j < lie; j++)
        {
            printf("%c", brr[i][j]);
        }
        printf("\n");
    }

    return 0;
}