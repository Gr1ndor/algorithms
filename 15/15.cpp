#include <iostream>

int hash(char data) {
	return (int)(data);
}

int hashSum(std::string str) {
	int sum = 0;
	for (size_t i = 0; i < str.length(); i++)
		sum += hash(str[i]);
	return sum;
}

void coins(int data) {
	int key = 0;
	int arr[5] = { 50, 10, 5, 2, 1 };
	for (size_t i = 0; i < 5; i++)
	{
		key = data / arr[i];
		data %= arr[i];
		std::cout << "Koins " << arr[i] << " = " << key << std::endl;
	}
}

int main()
{
	//task1
	std::string str;
	std::cout << "Enter string" << std::endl;
	std::cin >> str;
	std::cout << "Sum of keys = " << hashSum(str) << std::endl;
	//task2
	coins(98);
}