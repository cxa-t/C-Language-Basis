#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//void chek_sys()
//{
//	//int i = 1;
//	//if (*(char*)&i == 1)
//	//	printf("小端字节序");
//	//else if(*(char*)&i == 0)
//	//	printf("大端字节序");
//
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	if (un.c == 1)
//		printf("小端字节序");
//	else
//		printf("大端字节序");
//}

//int main()
//{
//	//int a = 0x12ff0619;
//	//chek_sys();
//	
//	//4,294,967,232
//	char a = 128;
//	printf("%u\n", a);
//
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	a = 128;
//	printf("%u\n", a);
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	return 0;
//}

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}

////X86环境 小端字节序
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

struct S1 
{ 
	char c1; 
	int i;   
	char c2; 
};
struct S2 { char c1; char c2; int i; };  // 8字节

struct 
{
	int a;
	char b;
	float c;
} x;

struct 
{
	int a;
	char b;
	float c;
} a[20], *p;

union Un {
	char c;  // 1字节
	int i;   // 4字节
};

//int main()
//{
//	//printf("%p\n", &(u.c));
//	//printf("%p\n", &(u.i));
//	//printf("%p\n", &(u));
//
//	union Un un = { 0 };
//	un.i = 0x11223344;  // 先赋给int
//	un.c = 0x55;        // 改低字节的char
//	printf("%x\n", un.i);  // 输出11223355，低字节被改了
//
//	return 0;
//}

union Un1 {
	char c[5];  // 5字节，对齐1
	int i;      // 4字节，对齐4
};
// 大小：max(5,4)=5，但最大对齐4，5不是4倍数 → 补到8字节
union Un2 {
	short c[7];  // 14字节，对齐2
	int i;       // 4字节，对齐4
};
// 大小：max(14,4)=14，最大对齐4，14不是4倍数 → 补到16字节
int main() 
{
	//printf("%d\n", sizeof(union Un1));  // 8
	//printf("%d\n", sizeof(union Un2));  // 16

	//struct S3 { 
	//	double d; //8 8  8
	//	char c;   //1 8  1
	//	int i;    //4 8  4
	//};      // 先算出是16字节，最大对齐数8
	//struct S4 
	//{
	//	char c1;      // 1字节
	//	struct S3 s3; // 16字节
	//	double d;     // 8字节
	//};	
	//// 输出多少？32！
	//printf("%d\n", sizeof(struct S4));  

	//struct S
	//{
	//	int _a : 2;   // 占2bit
	//	int _b : 5;   // 占5bit
	//	int _c : 10;  // 占10bit
	//	int _d : 30;  // 占30bit
	//};
	//
	//struct S s = { 0 };
	//s._a = 3;
	//s._b = 30;
	//s._c = 


	struct S 
	{
		char a : 3;
		char b : 4;
		char c : 5;
		char d : 4;
	};

	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;


	//printf("%d\n", sizeof(struct S));
	return 0;
 }






