#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%d\n", __LINE__);
//	return 0;
//}

// 定义一个高级调试打印宏
#define DEBUG_PRINT \
			printf("file:%s\tline:%d\tdate: %s\ttime:%s\n",\
                    __FILE__, __LINE__, __DATE__, __TIME__)

#define SQUARE(x) x*x
#define SAFE_SQUARE(x) ((x)*(x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//int main() 
//{
//	int x = 5, y = 8;
//	int z = MAX(x++, y++); 
//	printf("%d %d %d", x, y, z);
//
//	//int a = 5;
//	//int result = 0;
//	//result = SQUARE(a + 1);
//	//printf("%d\n", result);
//	//result = SAFE_SQUARE(a + 1);
//	//printf("%d\n", result);
//
//	//DEBUG_PRINT;
//	//printf("%d\n", __STDC__);
//
//	return 0;
//}

//
//#define MAX 1
//int main()
//{
//#if defined(MAX) && defined(MAX_NUM)
//	printf("hehe\n");
//#endif
//
//#ifdef MAX
//	printf("hehe\n");
//#endif 
//
//#if !defined(MAX)
//	printf("hehe\n");
//#endif
//
//#ifndef MAX
//	printf("hehe\n");
//#endif
//	return 0;
//}

int main()
{
#ifdef VERSION
	printf("Running version: %s\n", VERSION);
#else
	printf("Running default version.\n");
#endif
	return 0;
}

