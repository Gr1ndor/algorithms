#include <iostream>

void swap(int &x, int &y)
{
    int a = x;
    x = y;
    y = a;
}

void sortIns(int* arr, size_t first, size_t last)
{
    size_t length = last - first;
    for (size_t i = (first + 1); i <= last; i++)
    {
        int k = arr[i];
        size_t j = i - 1;
        while (j >= first && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}

void printArr(int *arr, size_t length)
{
    for (size_t i = 0; i < length; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

void impSort(int *arr, size_t first, size_t last)
{
    if ((last - first) < 10)
        sortIns(arr, first, last);
    else
    {
        size_t min = first;
        size_t max = last;
        size_t c = (first + last) / 2;
        if (arr[c] < arr[min])
            swap(arr[c], arr[min]);
        if (arr[max] < arr[min])
            swap(arr[min], arr[max]);
        if (arr[max] < arr[c])
            swap(arr[max], arr[c]);
        int med = arr[c];
        do
        {
            while (arr[min] < med)
                min++;
            while (arr[max] > med)
                max--;
            if (min <= max)
            {
                swap(arr[min], arr[max]);
                min++;
                max--;
            }
        } while (min <= max);
        if (min < last)
            impSort(arr, min, last);
        if (max > first)
            impSort(arr, first, max);
    }
}

void bSort(int* arr, size_t length)
{
    const size_t max = length;
    const size_t  count = 10;
    int** baskets = new int* [count];
    for (size_t i = 0; i < count; i++)
    {
        baskets[i] = new int[max+1];
    }
    for (size_t i = 0; i < count; i++)
    {
        baskets[i][max] = 0;
    }
    for (int dig = 1; dig < 1000000000; dig*=10)
    {
        for (size_t i = 0; i < max; i++)
        {
            int x = (arr[i] / dig) % count;
            baskets[x][baskets[x][max]++] = arr[i];
        }
        int p = 0;
        for (size_t i = 0; i < count; i++)
        {
            for (size_t j = 0; j < baskets[i][max]; j++)
            {
                if (baskets[i][j] % 2 == 1)
                {
                    break;
                }
                while (arr[p] % 2 == 1)
                {
                    p++;
                }
                arr[p++] = baskets[i][j];
            }
            baskets[i][max] = 0;
        }
    }

    for (size_t i = 0; i < count; i++)
        delete[] baskets[i];
    delete [] baskets;
}

int main()
{
    const size_t length = 12;
    int arr[12]{ 0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3 };
    printArr(arr, 12);
    //impSort(arr, 0, 11);
    bSort(arr, length);
    printArr(arr, 12);
    return 0;
}