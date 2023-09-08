#define _CRT_SECURE_NO_WARNINGS 1 

//***************************************//
//*********  模拟实现库函数qsort	*********//
//*********      Li Huayang		*********//
//*********      2023/09/07		*********//
//***************************************//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stu
{
	char name[20];
	int age;
};

//////*****  交换函数（逐字节交换）  *****/////
void Swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

//////*****  自定义整型比较函数  *****/////
int cmp_int(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);	//接收到的指针是泛型，强制转换为整形指针
}

//////*****  自定义结构体比较函数（比较name）  *****/////
//e1 -- 被比较的第一个元素的起始地址
//e1 -- 被比较的第二个元素的起始地址
int cmp_struct_Stu_name(const void* e1, const void* e2)
{
	return (strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name));	//接收到的指针是泛型，强制转换为结构体指针
}

//////*****  自定义结构体比较函数（比较age）  *****/////
int cmp_struct_Stu_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}


//////*****  排序函数  *****/////
//base -- 数组首元素地址
//size -- 数组元素个数
//width -- 每个元素占用空间大小，单位为字节
//e1 -- 被比较的第一个元素的起始地址
//e1 -- 被比较的第二个元素的起始地址
//cmp -- 函数指针（指向自定义比较函数），用于比较两个元素的大小，根据被比较元素类型，需要自定义不同的比较函数
void my_qsort(void* base, int size, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		int flag = 1;	//标志位初始化假设有序，1代表有序，0代表无序
		for (j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j*width ,(char*)base + (j + 1)*width) > 0)
			{
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);	//交换
				flag = 0;	//发生交换，则代表无序，标志位置0
			}
		}
		if (flag)	//判断标志位，为1则代表已经有序，跳出循环
		{
			break;
		}
	}
}



int main()
{
	//创建一维整形数组，乱序
	int arr[] = { 7, 5, 2, 9, 6, 4, 0, 3, 8, 1 };
	//创建结构体数组
	struct Stu s[3] = { { "zhangsan", 15 }, { "lisi", 30 }, { "wanger", 25 } };
	//计算元素个数
	int sz_arr = sizeof(arr) / sizeof(arr[0]);
	int sz_s = sizeof(s) / sizeof(s[0]);

	//一维整形数组排序
	my_qsort(arr, sz_arr, sizeof(arr[0]), cmp_int);
	//结构体数组排序
	my_qsort(s, sz_s, sizeof(s[0]), cmp_struct_Stu_name);

	//打印排序后的一维数组
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


/////*****  整形数组冒泡排序  *****/////
//void bubble_sort(int* parr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)	//冒泡排序趟数
//	{
//		int j = 0;
//		int flag = 1;	//标志位，判断本趟冒泡是否有次序交换
//		for (j = 0; j < sz - 1 - i; j++)	//本趟冒泡排序的冒泡次数
//		{
//			int tmp = 0;
//			if (parr[j]>parr[j + 1])
//			{
//				tmp = parr[j];
//				parr[j] = parr[j + 1];
//				parr[j + 1] = tmp;
//				flag = 0;	//有次序交换，标志位置0，进行下一趟冒泡
//			}
//		}
//		if (flag == 1)	//没有次序交换，则数组已经有序，跳出循环
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'b';
//	printf("%c\n", ch);
//
//	char* p = "abcdef";	//这里的"abcdef"是常量字符串，存在只读常量池，同样的字符串只保存一次，相当于先创建"abcdef"；再把首元素地址给p；
//	//*p = 'w';	//常量字符串不能通过指针修改
//	char arr[] = "abcdef"; //这里的"abcdef"在字符数组里，是变量，可以修改
//	arr[0] = 'w';
//	printf("%c\n", *arr);
//	printf("%s\n", arr);
//	printf("%c\n", *p);
//	printf("%s\n", p);
//	char(*p1)[7] = &arr;
//	char* p2 = arr;
//	return 0;
//}

//void print1(int a[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", a[i][j]);
//			//printf("%d ", *(*( a + i)+ j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7 };
//	print1(arr, 3, 5);
//	int(*pa)[5] = arr;
//	int j = sizeof(pa);
//	printf("%d\n", j);	//数组指针，函数指针都是只占用一个指针的空间（4/8个字节）
//	return 0;
//}



