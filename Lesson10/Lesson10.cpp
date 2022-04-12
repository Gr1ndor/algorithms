#include <iostream>

struct Node {
	char x;
	Node* next;
};
struct List {
	Node* head;
	size_t items;
	size_t size;
};

void init(List* l) {
	l->head = NULL;
	l->size = 0;
}

void ins(List* list, char a) {
	Node* node = new Node;
	node->next = NULL;
	node->x = a;
	Node* cur = list->head;
	if (list->size == 0)
	{
		list->head = node;
		list->size++;
		return;
	}
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	list->size++;
}

void printList(List* list) {
	Node* cur = list->head;
	while (cur->next != NULL)
	{
		std::cout << cur->x << " -> ";
		cur = cur->next;
	}
	std::cout << cur->x << std::endl;
}

void checkList(List* list) {
	size_t cir = 0;
	size_t sq = 0;
	size_t fig = 0;
	Node* cur = list->head;
	while (cur != NULL)
	{
		switch (cur->x)
		{
		case '(':
			cir++;
			break;
		case '[':
			sq++;
			break;
		case '{':
			fig++;
			break;
		case ')':
			cir--;
			if (cir < 0)
			{
				std::cout << "Sequence is not correct" << std::endl;
				return;
			}
			break;
		case ']':
			sq--;
			if (sq < 0)
			{
				std::cout << "Sequence is not correct" << std::endl;
				return;
			}
			break;
		case '}':
			fig--;
			if (fig < 0)
			{
				std::cout << "Sequence is not correct" << std::endl;
				return;
			}
			break;
		}
		cur = cur->next;
	}
	if (cir == 0 && sq == 0 && fig == 0)
		std::cout << "Sequence is correct" << std::endl;
	else
		std::cout << "Sequence is not correct" << std::endl;
}

void copyList(List* copy, List* orig) {
	Node* cur = orig->head;
	while (cur != NULL)
	{
		ins(copy, cur->x);
		cur = cur->next;
	}
}

void checkSortList(List* list) {
	Node* cur = list->head;
	int count = 0;
	int count2 = 0;
	while (cur->next != NULL)
	{
		if (cur->x >= cur->next->x)
			count--;
		if (cur->x <= cur->next->x)
			count2++;
		cur = cur->next;
	}
	if (count == (list->size - 1)*-1 || count2 == list->size - 1)
	{
		std::cout << "Sequence is sorted" << std::endl;
	}
	else
	{
		std::cout << "Sequence is not sorted" << std::endl;
	}
}

int main()
{
	//task 1
	std::string str;
	List* list = new List;
	init(list);
	std::cout << "Enter sequence of brackets: ";
	std::cin >> str;
	for (size_t i = 0; i < str.length(); i++)
		ins(list, str[i]);
	checkList(list);
	// task 2
	List* list2 = new List;
	init(list2);
	copyList(list2, list);
	printList(list);
	printList(list2);
	//task 3
	checkSortList(list);
	delete list2;
	delete list;
}