

#include"stdio.h"
#include"conio.h";
#include <stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

//Input array
void input(int *a, int n, int i=0)
{
	if (i == n)
	{
		return;
	}
		printf("Nhap vao phan tu a[%d] : ",i);
		scanf_s("%d", &a[i]);
		input(a, n ,i+1);
}

//Xuat mang
void output(int *a, int n, int i)
{
	if (i == n)
	{
		return;
	}
        printf("%d ", a[i]);
		output(a, n, i+1);

}

//Tim max, min
int maxArray(int *a, int n, int i, int max)
{
	if (i == n)
	{
		return max;
	}
	else
	{
		if (a[i] > max)
		{
			max = a[i];
			maxArray(a, n, i+1, max);
		}
		else
		{
			maxArray(a, n, i+1, max);
		}
	}
}
int minArray(int *a, int n, int i, int min)
{
	if (i == n)
		return min;
	else
	{
		if (a[i] < min)
		{
			min = a[i];
			minArray(a, n, i + 1, min);
		}
		else
		{
			minArray(a, n, i + 1, min);
		}
	}
}

void highRecursion()
{
	int n,i=0;
	int a[200];

	do
	{
		cout << "\nInput total elements of the array:  ";
		cin >> n;
		if (n < 0)
			cout << ("\nError! Please input number >0");

	} while (n < 0);

	cout << "\n=====================================================";
	cout << "\n1. Input and Output array";
	cout << "\n2. Find max, min of array";
	cout << "\n=====================================================";

	int type = 0;
	do
	{
		cout << "\n\nPlease to choose type of action: ";
		cin >> type;
		switch (type)
		{
		case 1:
		{
				  //Nhap tong so phan tu cua mang
				  input(a, n,i);
				  cout << "\nMang vua nhap: ";
				  output(a, n,i);
				  break;
		}
		case 2:
		{
				  input(a,n,i);
				  int max = 0, min=a[0];
				  cout << "\nMax element:  "<<maxArray(a, n, i, max);
				  cout << "\nMin element:  " << minArray(a, n, i, min);
		}
		default:
			break;
		}
	} while (type != 0);
}