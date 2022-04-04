#include <iostream>

void printMatrix(int matrix[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void sortMatrix(int matrix[3][3])
{
	int x = 0;
	for (size_t k = 0; k < 8; k++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				if (matrix[i][j] > matrix[i][j + 1])
				{
					x = matrix[i][j];
					matrix[i][j] = matrix[i][j + 1];
					matrix[i][j + 1] = x;
				}
			}
			if (i<2 && matrix[i][2] > matrix[i+1][0])
			{
				x = matrix[i][2];
				matrix[i][2] = matrix[i+1][0];
				matrix[i+1][0] = x;
			}
		}
	}
}

void initArr(int arr[11])
{
	std::cout << "Enter 11 numbers: " << std::endl;
	for (size_t i = 0; i < 11; i++)
	{
		std::cin >> arr[i];
	}
}

void invertArr(int arr[11])
{
	for (size_t i = 0; i < 5; i++)
	{
		int x = arr[i];
		arr[i] = arr[10 - i];
		arr[10 - i] = x;
	}
}

void printArr(int arr[11])
{
	for (size_t i = 0; i < 11; i++)
	{
		std::cout << arr[i] <<' ';
	}
	std::cout << std::endl;
}

void findNum(int arr[11])
{
	for (size_t i = 0; i < 11; i++)
	{
		int x = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
		if (x > 400)
		{
			std::cout << i+1 << " element = " << arr[i] << ". Result more than 400: " << x << std::endl;
		}
	}
}

int main()
{
	int matrix[3][3]{1,9,2,5,7,6,4,3,8};
	printMatrix(matrix);
	sortMatrix(matrix);
	printMatrix(matrix);

	int arr[11]{ 0 };
	initArr(arr);
	invertArr(arr);
	printArr(arr);
	findNum(arr);
}
