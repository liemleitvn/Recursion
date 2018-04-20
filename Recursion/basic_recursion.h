


#include"stdio.h"
#include"conio.h";
#include <stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

void input(int &n)
{
	cout << "\nInput number which you want calculatle:  ";
	cin >> n;
}

//S(n) = 1 + 2 + 3 +....+ n
int sum(int n)
{
	if (n == 1)
		return 1;
	else
		return sum(n - 1) + n;
}

//tinh tich cac so tu 1 den n
int accumulationZeroToNumber(int n)
{
	int S = 1;
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return S = n*accumulationZeroToNumber(n - 1);
	}
}

//Tinh tich binh phuong tu 0 den n
int accmulationSquare(int n)
{
	if (n == 0)
		return 1;
	else
		return n*n* accmulationSquare(n - 1);
}

//Tinh tong nghich dao S=1+1/2+...+1/n
float sumInverse(int n)
{
	if (n == 1)
		return 1;
	else 
		return (float)(sumInverse(n - 1) + 1.0 / n);
}

//Tinh n^x = 1 * n * n(2) *...* n(x)
float nBacx(int n, int x)
{
	if (x == 0)
		return 1;
	if (x > 0)
		return nBacx(n,x - 1)*n;
	if (x < 0)
		return nBacx(n,x + 1)*1.0 / n;

}

//Tinh S(n) = 1 + 1.2 + 1.2.3 +....+1.2.3....n
int sumAndAccumulate(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		/*De quy phi tuyen
		int accumulate = 1;
		for (int i = 2; i <= n; i++)
		{
			accumulate *= i;
		}
		return sumAndAccumulate(n - 1) + accumulate;*/
		return sumAndAccumulate(n - 1) + accumulationZeroToNumber(n);
	}
}

//Tinh S(n,x) = 1+ n + n^2 + n^3 +...+n^x
int tongnBacx(int n, int x)
{
	if (x == 0)
	{
		return 1;
	}
	else
	{
		return tongnBacx(n, x - 1) + nBacx(n, x);
	}
}

//Tinh S(n) = 1 + 1/(1 + 2) + 1/(1 + 2 + 3) +....+ 1/(1 + 2 + 3 +...+ n)
float sumn(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return sumn(n - 1) + 1.0 / (sum(n));
}


//S(n,x) = n + (n^2)/2! + (n^3)/3! + ... + (n^x)/x!
float noName(int n, int x)
{
	if (n = 0)
		return 0;
	else
	{
		if (x = 1)
			return n;
		else
		{
			return noName(n, x - 1) + (nBacx(n, x) / accumulationZeroToNumber(x));
		}
	}
}

//Tim uoc so le lon nhat cua n
int divisor(int n)
{
	if (n % 2 != 0)
		return n;
	else
		divisor(n / 2);
}

//S(n) = sqrt(2+sqrt(s+sqrt(2+.....))...)), n dau sqrt
//square root: can bat hai
float squareRoot(int n)
{
	if (n == 1)
		return sqrt(2.0);
	else
		return sqrt(2 + squareRoot(n - 1));
}

//S(n) = sqrt(n+sqrt(n-1 +sqrt(n-2 +....+sqrt(2+sqrt(1))...)), n dau can
float squareRootNumber1(int n)
{

	return 0;
}

//S(n) = sqrt(1+sqrt(2+sqrt3(4+.....+sqrt(n)))...)), n dau can
float squareRootNumber2(int n, int index)
{
	int i = 0;
	
	if (n == 0) 
	{
		cout << "Error!! Please input n > 0";
		return 0;
	}
	else if (n < 0)
	{
		cout << "Error!! Please input n > 0";
		return 0;
	} 
	else 
	{
		if (index == 0)
			return sqrt(n);
		else
			return sqrt((n-index) + squareRootNumber2(n, index-1));
	}
}

//S(n) = 1/1+(1/1+(1/1+...1/1+(1/1+(1/(1+1))...), co n dau thap phan
float noName1(int n)
{
	if (n == 1)
		return 0.5;
	else
		return(1.0 / (1 + noName1(n-1)));
}
//Tinh so chu so cua mot so nguyen
int countN(int n)
{
	if (n == 0)
		return 0;
	else
		return (countN(n / 10) + 1);
}

//Tinh tong chu so cua so nguyen duong
int sumCountN(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else 
		return (sumCountN(n / 10) + n % 10);
}

//Tinh tong cac chu so le trong so nguyen
int sumOddNumber(int n)
{
	if (n == 0)
		return 0;
	else
	{
		if ((n % 10)%2 == 0)
			sumOddNumber(n / 10);
		else 
		return (sumOddNumber(n / 10) + n % 10);
	}
	
}
//Tim chu so dau tien cua so nguyen duong n
int Firstnumeral(int n)
{
	if (n / 10 == 0)
		return n;
	else
		return Firstnumeral(n / 10);
}

//Tim so dao nguoc cua so nguyen n
int inverseNumber(int n, int &inverse)
{
	if (n == 0)
		return 0;
	else
	{
		inverse = inverse * 10 + n % 10;
		inverseNumber(n / 10,inverse);
		return inverse;
	}
}

//Tim chu so lon nhat cua so nguyen 
int maxNumeralInN(int n, int &max)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		if (n % 10 > max)
		{
			max = n % 10;
			maxNumeralInN(n / 10,max);
		}
		else
		{
			maxNumeralInN(n / 10, max);
		}
	}
	return max;
}

//Xac dinh xem so nguyen n co toan le hay khong
bool checkNumber(int n)
{
	if (n == 0)
		return true;
	else
	{
		if ((n % 10) % 2 == 0)
		{
			return false;
		}
		else
			return checkNumber(n / 10);
	}
}

void basicRecursion()
{
	int n;
	cout << "\n=====================================================";
	cout << "\n1. S(n) = 1.2.3...n ";
	cout << "\n2. S(n) = 1 . 2^1 . 2^2 ....2^n ";
	cout << "\n3. S(n) = 1 + 1/2 + 1/3 + ...+ 1/n ";
	cout << "\n4. S(n) = n^x = 1 * n * n(2) *...* n(x) ";
	cout << "\n5. S(n) = 1 + 1.2 + 1.2.3+....+1.2.3...n ";
	cout << "\n6. S(n,x) = 1 + n + n^2 + n^3 +... + n^x ";
	cout << "\n7. S(n) = 1 + 1/(1 + 2) + 1/(1 + 2 + 3) +....+ 1/(1 + 2 + 3 +...+ n)";
	cout << "\n8. S(n,x) = n + (n^2)/2! + (n^3)/3! + ... + (n^x)/x!";//Ra ket qua sai
	cout << "\n9. Find max divisor of number";
	cout << "\n10. Square root of number ";
	cout << "\n11. S(n) = sqrt(1+sqrt(2+sqrt3(4+.....+sqrt(n)))...))";

	cout << "\n12. S(n) = 1/1+(1/1+(1/1+...1/1+(1/1+(1/(1+1))...)";
	cout << "\n13. Count numeral in number ";//Dem so luong chu so cua 1 so
	cout << "\n14. Sum numeral in number";//Tinh tong cac chu so trong so nguyen duong
	cout << "\n15. Sum odd number in number";//Tinh tong cac chu so le cua so nguyen
	cout << "\n16. Find first numeral of number";//Tim chu so dau tien cua so nguyen 
	cout << "\n17. Find inverse of number";//Tim so dao 
	cout << "\n18. Find max numeral in number ";//Tim chu so lon nhat cua so nguyen
	cout << "\n19. Check odd number in number ";//Kiem tra xem so nguyen n co phai toan so le
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
				  input(n);
				  cout << "\nAccumulattion from 1 to n:  " << accumulationZeroToNumber(n);
		}
			break;
		case 2:
		{
				  input(n);
				  cout << "\nAccumulation square from 1 to n: " << accmulationSquare(n);

				  break;
		}
		case 3:
		{
				  input(n);
				  printf("\nSum from 1 to 1/n:  %0.3f", sumInverse(n));
				  break;
		}
		case 4:
		{
				  input(n);
				  int x;
				  cout << "\nNhap so mu can tinh: ";
				  cin >> x;
				  printf( "\nn^x: =  %0.3f", nBacx(n, x));
				  break;
		}
		case 5:
		{
				  input(n);
				  cout << "\nS(n) = 1 + 1.2 + 1.2.3+....+1.2.3...n =  " << sumAndAccumulate(n);
				  break;
		}
		case 6:
		{
				  int x;
				  input(n);
				  cout << "Input x: ";
				  cin >> x;
				  cout << "\nS(n,x) = 1 + n + n^2 + n^3 +... + n^x =   " << tongnBacx(n, x);
				  break;
		}
		case 7:
		{
				  input(n);
				  printf("\nS(n) = 1 + 1/(1 + 2) + 1/(1 + 2 + 3) +....+ 1/(1 + 2 + 3 +...+ n) =  %0.3f",sumn(n));
				  break;
		}
		case 8:
		{
				  input(n);
				  int x;
				  cout << "Input x: ";
				  cin >> x;
				  printf("\nS(n,x) = n + (n^2)/2! + (n^3)/3! + ... + (n^x)/x! =  %0.3f", noName(n, x));
				  break;
		}
		case 9:
		{
				  input(n);
				  cout << "\nMax divisor of number:  " << divisor(n);
				  break;
		}
		case 10:
		{
				   input(n);
				   printf("\nSquare root of %d la: %0.3f", n, squareRoot(n));
				   break;
		}
		case 11:
		{
				   input(n);
				   printf("\nS(n) = sqrt(1+sqrt(2+sqrt3(4+.....+sqrt(n)))...)) = %0.3f", squareRootNumber2(n, n-1));
				   break;
		}
		case 12:
		{
					input(n);
					printf("\nS(n) = 1/1+(1/1+(1/1+...1/1+(1/1+(1/(1+1))...) = :  %0.3f", noName1(n));
					break;
		}
		case 13:
		{
				   input(n);
				   cout << "\nNumber " << n << " have " << countN(n) << " numeral";
				   break;
		}
		case 14:
		{
				   input(n);
				   cout << "\nSum numeral of " << n << ":  "<<sumCountN(n);
				   break;
		}
		case 15:
		{
				   input(n);
				   cout << "\nSum odd number of " << n << ":  " << sumOddNumber(n);
				   break;
		}
		case 16:
		{
				   input(n);
				   cout << "First numeral of " << n << " : " << Firstnumeral(n);
				   break;
		}
		case 17:
		{
				   input(n);
				   int inverse = 0;
				   cout << "\nInverse of " << n << " :  " << inverseNumber(n, inverse);
				   break;
		}
		case 18:
		{
				   input(n);
				   int max = 0;
				   cout << "Max numeral in " << n << " : " << maxNumeralInN(n, max);
				   break;
		}
		case 19:
		{
				   input(n);
				   bool result = checkNumber(n);
				   if (result)
					   cout << "Cac chu so trong so " << n << " toan la so le";
				   else
					   cout << "Cac chu so trong so " << n << " khong phai toan so le";
		}
		default:
			break;
		}
	} while (type != 0);
	
}