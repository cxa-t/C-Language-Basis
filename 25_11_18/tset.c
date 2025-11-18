#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

// 结构体定义
struct Stu //学生
{
    char name[20]; //名字
    int age; //年龄
};

// 1. 比较整数的回调函数 (int_cmp)
// 实现升序排序
int int_cmp(const void* p1, const void* p2)
{
    // 将void*指针强制转换为int*，然后解引用相减。
    return (*(int*)p1 - *(int*)p2);
}

// 2. 比较结构体年龄的回调函数 (cmp_stu_by_age)
// 实现按年龄升序排序
int cmp_stu_by_age(const void* e1, const void* e2)
{
    // 转换为struct Stu*，访问age成员后相减
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

// 3. 比较结构体姓名的回调函数 (cmp_stu_by_name)
// 实现按姓名（字符串）升序排序
int cmp_stu_by_name(const void* e1, const void* e2)
{
    // 转换为struct Stu*，访问name成员，使用strcmp比较字符串大小
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

// 打印结构体数组的辅助函数
static void PrintStu(struct Stu s[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("{%s, %d} ", s[i].name, s[i].age);
    }
    printf("\n");
}



//通用交换函数
void swap(void* p1, void* p2, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        char temp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = temp;
    }
}
//通用排序函数
void bubble_sort_qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) // PDF 中为 bubble 函数
{
    int i = 0;
    for (i = 0; i < num - 1; i++) // 外层循环：趟数
    {
        int j = 0;
        for (j = 0; j < num - 1 - i; j++) // 内层循环：比较未归位元素
        {
            // 元素寻址
            void* current_ele = (char*)base + j * size;
            void* next_ele = (char*)base + (j + 1) * size;

            // 调用回调函数进行比较
            if (compar(current_ele, next_ele) > 0)
            {
                // 执行通用交换
                swap(current_ele, next_ele, size);
            }
        }
    }
}
 

// 测试整数排序
void test_int_sort()
{
    int arr[] = { 1, 23, 15, 73, 29, 72, 24, 6, 8, 90 };
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 调用 qsort 排序整数
    bubble_sort_qsort(arr, sz, sizeof(int), int_cmp);

    printf("Sorted array (int): ");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

// 测试结构体排序
void test_struct_sort()
{
    struct Stu s[] = { {"zhangsan", 20}, {"lisi", 30}, {"wangwu", 15} };
    int sz = sizeof(s) / sizeof(s[0]);

    printf("Original Structs: ");
    PrintStu(s, sz);

    // 1. 按年龄排序
    // 注意：qsort是in-place排序，会修改原数组s
    bubble_sort_qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
    printf("Sorted Structs (by age): ");
    PrintStu(s, sz);

    // 2. 按姓名排序 (需要重新初始化或使用一个新数组进行演示)
    struct Stu s_name[] = { {"extreme35", 20}, {"jack", 21}, {"daiwei", 17} };
    printf("Original Structs (for name sort): ");
    PrintStu(s_name, sz);

    bubble_sort_qsort(s_name, sz, sizeof(s_name[0]), cmp_stu_by_name);
    printf("Sorted Structs (by name): ");
    PrintStu(s_name, sz);
    printf("\n");
}

int main()
{
    test_int_sort();
    test_struct_sort();

    return 0;
}

//
//void bubble_sort(int* arr, int n) 
//{
//    for (int i = 0; i < n - 1; i++) 
//    {
//        // 最后i个元素已经排好序
//        for (int j = 0; j < n - 1 - i; j++) 
//        {
//            if (arr[j] > arr[j + 1]) 
//            {
//                // 交换元素
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void print_array(int arr[], int n) 
//{
//    for (int i = 0; i < n; i++) 
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}

// 
//int main() 
//{
//    int arr[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("排序前: ");
//    print_array(arr, n);
//
//    bubble_sort(arr, n);
//
//    printf("排序后: ");
//    print_array(arr, n);
//
//    return 0;
//}


