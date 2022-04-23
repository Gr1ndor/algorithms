#include <iostream>

std::string codeCes(std::string mess, int key) {
	key %= 26;
	for (size_t i = 0; i < mess.length(); i++)
	{
		if (mess[i] == ' ')
			i++;
		if ((int)(mess[i]) < (int)('a'))
			mess[i] += 32;
		int n = (int)(mess[i]);
		n = n + key;
		if ((char)(n) < 'a')
			n += 26;
		if ((char)(n) > 'z')
			n -= 26;
		mess[i] = (char)(n);
	}
	return mess;
}

std::string code(std::string mess, int key) {
	std::string newstr;
	int cur = 0;
	int lines = mess.length() / key;
	if (mess.length() % key != 0)
		lines++;
	for (size_t i = 0; i < key; i++)
	{
		int x = i;
		for (size_t j = 0; j < lines; j++)
		{
			if (x >= mess.length())
				newstr.insert(cur, 1, 'x');
			else
				newstr.insert(cur, 1, mess[x]);;
			x += key;
			cur++;
		}
	}
	return newstr;
}

int main()
{
	//task1
	int key = 3;
	std::string str = "Thisisasecretmessage1";
	std::cout << "Caesar code message:" << codeCes(str, key) << std::endl;
	std::cout << "Caesar decode message:" << codeCes(codeCes(str, key), -key) << std::endl;
	//task2
	key = 5;
	std::cout << "code message:" << code(str, key) << std::endl;
	std::cout << "decode message:" << code(code(str, key), code(str, key).length()/key) << std::endl;
}