# Pointer-ArrayPointer
C语言学习--指针、数组指针、函数指针，数组指针的数组、函数指针的数组。学习了以上不同类型的表示形式。

#include <stdio.h>

int Add(int x, int y){
	return x + y;
}

int Sum(int x, int y){
	return x - y;
}

int Mul(int x, int y){
	return x * y;
}

int Div(int x, int y){
	return x / y;
}

int main()
{
	//整形指针
	int a = 0;
	int* pa = &a;

	//字符指针
	char ch = '0';
	char* pch = &ch;

	//数组指针，指针+-步长等于数组大小
	char charr[5] = "abcd";
	int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int(*parr1)[10] = &arr1;	//整形数组指针，类型为int(*)[10]，代表指向的数组有10个元素，元素类型为int
	int(*parr2)[10] = &arr2;
	char(*pcharr)[5] = &charr;	//字符数组指针，类型为char(*)[5]，代表指向的数组有5个元素，元素类型为char
	
	//整形指针，指向arr第一个元素，+-步长为一个整形大小
	int* parr0 = &arr1[0];

	//函数指针,存放函数地址，类型为int(*)(int, int)，代表指向的函数有两个输入参数，类型为int，返回类型也为int
	int(*pfAdd)(int, int) = &Add;
	int(*pfSum)(int, int) = &Sum;
	int(*pfMul)(int, int) = &Mul;
	int(*pfDiv)(int, int) = &Div;

	//指针数组，存放指针的数组（既然是数组，存放的是同一类型的指针）
	//整形指针数组，有10个元素，类型为int*
	int* p[10] = { arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], arr1[7], arr1[8], arr1[9] };

	//字符指针数组，有2个元素，类型为char*
	char* pch[5] = { charr[0], charr[1], charr[2], charr[3], charr[4] };

	//数组指针数组
	int(*parr[2])[10] = { parr1, parr2 };	//存放整形数组指针的数组，名字为parr，有2个元素，类型为int(*)[10];
	//int(*parr[2])[10] = { &arr1, &arr2 };

	//函数指针数组
	int(*pf[4])(int, int) = { pfAdd, pfSum, pfMul, pfDiv };	//存放函数指针的数组，名字为pf，有4个元素，类型为int(*)(int, int);
	//int(*pf[4])(int, int) = { &Add, &Sum, &Mul, &Div };
	return 0;
}
