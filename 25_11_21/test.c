#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct S
{
	char name[20];
	int age;
	float score;
};

int main()
{

	//打开文件
	FILE* pf = fopen("Extreme.txt","r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	////写文件
	//fputc('E', pf);
	//fputc('x', pf);
	//fputc('t', pf);
	//fputc('r', pf);
	//fputc('e', pf);
	//fputc('m', pf);
	//fputc('e', pf);
	//fputc('\n', pf);

	//char c = 'a';
	//for (c = 'a'; c <= 'z'; c++)
	//{
	//	fputc(c, pf);
	//}

	////读文件 -- 单字符
	//char c = 0;
	//c = fgetc(pf);
	//printf("%c", c);

	//puts(" ");

	////读文件 -- 循环读
	//while ((c = fgetc(pf)) != EOF)
	//{
	//	printf("%c", c);
	//}

	////写字符串
	//fputs("Extreme\n", pf);
	//fputs("35\n", pf);
	//fputs("ABCDEFG\n", pf);
	//fputs("HIJKLMN\n", pf);
	//fputs("OPQRSTUVWXYZ", pf);

	//char arr[10] = { 0 };
	//while (fgets(arr, 5, pf) != NULL)
	//{
	//	printf("%s", arr);
	//}

	//struct S s = { "张三", 20, 65.5f };
	////写文件 - 是以文本的形式写进去的
	//fprintf(pf, "%s %d %f", s.name, s.age, s.score);

	//struct S s = { 0 };
	////读文件 
	//fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));

	////打印在屏幕上看看
	//printf("%s %d %f\n", s.name, s.age, s.score);
	//fprintf(stdout, "%s %d %f\n", s.name, s.age, s.score);

	////读文件
	////现在文件里的内容是：Extreme 20 65.500000
	//char arr[100] = { 0 };
	//int ch = fgetc(pf);
	//printf("%c\n", ch);//E
	//fseek(pf, 8, SEEK_SET);//将光标定位在2，打印后续字符串
	//printf(fgets(arr, 11, pf));
	
	//fseek(pf, 0, SEEK_END);
	//printf("%d\n", ftell(pf));
	//printf("%d\n", strlen("Extreme 20 65.500000"));

	////读文件
	////现在文件里的内容是：Extreme 20 65.500000
	//char arr[100] = { 0 };
	//int ch = fgetc(pf);
	//printf("%c\n", ch);//E
	//fseek(pf, 8, SEEK_SET);//将光标定位在2，打印后续字符串
	//printf("%s\n",fgets(arr, 11, pf));
	//rewind(pf);
	//ch = fgetc(pf);
	//printf("%c\n", ch);//E

	//写
	char ch = 0;
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		fputc(ch, pf);
	}

	//判断是什么原因导致读取结束的
	if (feof(pf))
	{
		printf("遇到文件末尾，读取正常结束\n");
	}
	else if (ferror(pf))
	{
		perror("fputc");
	}

	//关闭文件
	fclose(pf);
	//防止野指针
	pf = NULL;
	
	return 0;
}

