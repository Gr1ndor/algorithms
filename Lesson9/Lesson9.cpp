#include <iostream>

struct node
{
    int pr;
    int dat;
};
const int length = 20;
node* arr[length];
int items;

void initQueue()
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] == NULL;
    }
    int items = 0;
}

void ins(int pr, int dat)
{
    if (items == length)
    {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    node* n = new node;
    n->dat = dat;
    n->pr = pr;
    arr[items] = n;
    items++;
}

node* rem()
{
    if (items == 0)
        return NULL;
    int min = arr[0]->pr;
    int idx = 0;
    for (size_t i = 1; i < items; i++)
    {
        if (min > arr[i]->pr)
        {
            idx = i;
            min = arr[idx]->pr;            
        }
    }
    node* n = arr[idx];
    while (idx < items - 1)
        arr[idx++] = arr[idx + 1];
    arr[idx] = NULL;
    items--;
    return n;
}

void printQueue()
{
    for (size_t i = 0; i < items; i++)
    {
        std::cout << arr[i]->pr << ", " << arr[i]->dat << "   ";
    }
    std::cout << std::endl;
}


size_t stack[length];
int head = -1;

bool push(size_t dat)
{
    if (head < (length - 1))
    {
        stack[++head] = dat;
        return true;
    }
    std::cout << "Stack is full" << std::endl;
    return false;
}

size_t pop()
{
    if (head != -1)
        return stack[head--];
    std::cout << "Stack is empty" << std::endl;
    return -1;
}

void intToDouble(int x)
{
    while (x > 0)
    {
        push(x%2);
        x /= 2;
    }
}

void printStack()
{
    while (head != -1)
    {
        std::cout << pop();
    }
    std::cout << std::endl;
}

int main()
{
    // first task
    initQueue();
    ins(3, 1);
    ins(2, 2);
    ins(1, 3);
    ins(4, 4);
    ins(5, 5);
    printQueue();
    node* n = rem();
    printQueue();
    //second task
    intToDouble(20);
    printStack();
}