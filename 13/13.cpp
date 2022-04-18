#include <iostream>

const size_t length = 6;
int matrix[length][length]{
    0, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0
};
int visit[length];
struct Node {
    int count;
    int num;
    Node* next;
    Node* prev;
};
struct List {
    Node* head;
    Node* tail;
};

void arrEmpty()
{
    for (size_t i = 0; i < length; i++)
    {
        visit[i] = 0;
    }
}

void search(int start)
{
    int stack[length]{0};
    int cur = 0;
    int nodes[length]{0}; 
    for (int i = 0; i < length; i++)
        nodes[i] = 0; 
    stack[cur] = start; 
    while (cur >= 0)
    {
        int node = stack[cur];
        stack[cur] = -1;
        cur--;
        if (nodes[node] == 1)
            continue;
        nodes[node] = 1;
        for (int j = length - 1; j >= 0; j--)
        {
            if (matrix[node][j] == 1 && nodes[j] != 1)
            {
                cur++;
                stack[cur] = j;
            }
        }
        std::cout << node << ", ";
    }
    std::cout << std::endl;
}

void search2(int start)
{
    visit[start] = 1;
    for (size_t i = 0; i < length; i++)
    {
        if (matrix[start][i] == 1 && visit[i] > 0)
        {
            visit[i] ++;
        }
        if (matrix[start][i] == 1 && visit[i] == 0)
        {
            search2(i);
        }
    }
}

void search3()
{
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            visit[j] += matrix[i][j];
        }
    }
}

void insList(List* list, int num, int count)
{
    Node* node = new Node;
    node->count = count;
    node->num = num;
    if (!list->head)
    {
        list->head = node;
        list->tail = node;
        list->head->next = NULL;
        list->tail->prev = NULL;
        return;
    }
    if (count < list->head->count)
    {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
        list->head = node;
        return;
    }
    Node* cur = list->head;
    while (cur != NULL && count >= cur->count)
        cur = cur->next;
    if (!cur)
    {
        node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
        return;
    }
    node->next = cur;
    node->prev = cur->prev;
    cur->prev->next = node;
    cur->prev = node;
}

void printList(List* list)
{
    Node* cur = list->tail;
    while (cur)
    {
        std::cout << "Vertex: " << cur->num << ' ';
        std::cout << "Half-Communications: " << cur->count << std::endl;
        cur = cur->prev;
    }
}

int main()
{
    //task 1
    for (size_t i = 0; i < length; i++)
    {
        search(i);
    }
    //task 2.1
    List* list = new List;
    list->head = NULL;
    int start = 1;
    search2(start);
    for (size_t i = 0; i < length; i++)
    {
        if (matrix[start][i] == 1 || matrix[i][start] == 1)
            if (visit[i] > 0)
                insList(list, i, visit[i]);
    }
    printList(list);
    //task 2.2
    arrEmpty();
    List* list2 = new List;
    list2->head = NULL;
    search3();
    for (size_t i = 0; i < length; i++)
    {
        if (visit[i] > 0)
            insList(list2, i, visit[i]);
    }
    std::cout << std::endl;
    printList(list2);
}