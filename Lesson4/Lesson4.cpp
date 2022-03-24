#include <iostream>

void tenToTwo(int x)
{
	if (x / 2 == 1)
		std::cout << x / 2;
	else
		tenToTwo(x / 2);
	std::cout << x % 2;
}

int exponentiation(int a, int b)
{
	if (b > 0)
	{
		return a * exponentiation(a, b-=1);
	}
	else
	{
		return 1;
	}
}

int exponentiation2(int a, int b)
{
	if (b>0)
	{
		if (b % 2 == 0)
		{
			return exponentiation2(a * a, b / 2);
		}
		else
		{
			return a * exponentiation2(a, b -= 1);
		}
	}
	else
	{
		return 1;
	}
}

int path(int arr[3][3], int x, int y)
{
	if (arr[x][y] == 1)
	{
		return 0;
	}
	if (x == 0 && y == 0)
		return 0;
	else
		if (x == 0 || y == 0)
			return 1;
		else
			return path(arr, x, y - 1) + path(arr, x - 1, y);
}

int main()
{
	tenToTwo(650);
	std::cout << std::endl;
	int arr[3][3]{ 0, 0, 0, 0, 1, 0, 0, 0, 0 };
	int x = 0;
	x = exponentiation(3, 3);
	std::cout << x << std::endl;
	x = exponentiation2(3, 3);
	std::cout << x << std::endl;
	x = path( arr, 2, 2);
	std::cout << x << std::endl;
	return 0;
}