#define _CRT_SECURE_NO_WARNINGS 1 

//***************************************//
//*********  ģ��ʵ�ֿ⺯��qsort	*********//
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

//////*****  �������������ֽڽ�����  *****/////
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

//////*****  �Զ������ͱȽϺ���  *****/////
int cmp_int(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);	//���յ���ָ���Ƿ��ͣ�ǿ��ת��Ϊ����ָ��
}

//////*****  �Զ���ṹ��ȽϺ������Ƚ�name��  *****/////
//e1 -- ���Ƚϵĵ�һ��Ԫ�ص���ʼ��ַ
//e1 -- ���Ƚϵĵڶ���Ԫ�ص���ʼ��ַ
int cmp_struct_Stu_name(const void* e1, const void* e2)
{
	return (strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name));	//���յ���ָ���Ƿ��ͣ�ǿ��ת��Ϊ�ṹ��ָ��
}

//////*****  �Զ���ṹ��ȽϺ������Ƚ�age��  *****/////
int cmp_struct_Stu_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}


//////*****  ������  *****/////
//base -- ������Ԫ�ص�ַ
//size -- ����Ԫ�ظ���
//width -- ÿ��Ԫ��ռ�ÿռ��С����λΪ�ֽ�
//e1 -- ���Ƚϵĵ�һ��Ԫ�ص���ʼ��ַ
//e1 -- ���Ƚϵĵڶ���Ԫ�ص���ʼ��ַ
//cmp -- ����ָ�루ָ���Զ���ȽϺ����������ڱȽ�����Ԫ�صĴ�С�����ݱ��Ƚ�Ԫ�����ͣ���Ҫ�Զ��岻ͬ�ıȽϺ���
void my_qsort(void* base, int size, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		int flag = 1;	//��־λ��ʼ����������1��������0��������
		for (j = 0; j < size - 1 - i; j++)
		{
			if (cmp((char*)base + j*width ,(char*)base + (j + 1)*width) > 0)
			{
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);	//����
				flag = 0;	//������������������򣬱�־λ��0
			}
		}
		if (flag)	//�жϱ�־λ��Ϊ1������Ѿ���������ѭ��
		{
			break;
		}
	}
}



int main()
{
	//����һά�������飬����
	int arr[] = { 7, 5, 2, 9, 6, 4, 0, 3, 8, 1 };
	//�����ṹ������
	struct Stu s[3] = { { "zhangsan", 15 }, { "lisi", 30 }, { "wanger", 25 } };
	//����Ԫ�ظ���
	int sz_arr = sizeof(arr) / sizeof(arr[0]);
	int sz_s = sizeof(s) / sizeof(s[0]);

	//һά������������
	my_qsort(arr, sz_arr, sizeof(arr[0]), cmp_int);
	//�ṹ����������
	my_qsort(s, sz_s, sizeof(s[0]), cmp_struct_Stu_name);

	//��ӡ������һά����
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


/////*****  ��������ð������  *****/////
//void bubble_sort(int* parr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)	//ð����������
//	{
//		int j = 0;
//		int flag = 1;	//��־λ���жϱ���ð���Ƿ��д��򽻻�
//		for (j = 0; j < sz - 1 - i; j++)	//����ð�������ð�ݴ���
//		{
//			int tmp = 0;
//			if (parr[j]>parr[j + 1])
//			{
//				tmp = parr[j];
//				parr[j] = parr[j + 1];
//				parr[j + 1] = tmp;
//				flag = 0;	//�д��򽻻�����־λ��0��������һ��ð��
//			}
//		}
//		if (flag == 1)	//û�д��򽻻����������Ѿ���������ѭ��
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
//	char* p = "abcdef";	//�����"abcdef"�ǳ����ַ���������ֻ�������أ�ͬ�����ַ���ֻ����һ�Σ��൱���ȴ���"abcdef"���ٰ���Ԫ�ص�ַ��p��
//	//*p = 'w';	//�����ַ�������ͨ��ָ���޸�
//	char arr[] = "abcdef"; //�����"abcdef"���ַ�������Ǳ����������޸�
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
//	printf("%d\n", j);	//����ָ�룬����ָ�붼��ֻռ��һ��ָ��Ŀռ䣨4/8���ֽڣ�
//	return 0;
//}



