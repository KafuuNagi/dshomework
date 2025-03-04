#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
void select_sort(int* num, int n);
void bubble_sort(int* num, int n);
void quick_sort(int* num, int left, int right);//递归快排函数 
int main()
{
    const int MAX = 10000;
    int a[MAX];


    cout << "请选择你想使用的排序方式：" << endl;
    cout << "1)冒泡排序" << "2)选择排序" << "3)快速排序" << endl;
    int choice;
    cin >> choice;

    cout << "排序前数据：" << endl;
    srand(time(0));
    for (int i = 0; i < MAX; ++i)
    {
        a[i] = rand() % 1000;//便于观察，取最高三位数 
        cout << setw(4) << a[i] << " \n"[(i + 1) % 10 == 0];
    }

    auto start = chrono::high_resolution_clock::now();
    if (choice == 1)
        bubble_sort(a, MAX);
    if(choice == 2)
        select_sort(a, MAX);
    if(choice == 3)
        quick_sort(a, 0, MAX - 1);
    auto end = chrono::high_resolution_clock::now();

    double seconds = chrono::duration<double>(end - start).count();

    cout << endl << endl << endl;
    cout << "排序后数据：" << endl;
    for (int i = 0; i < MAX; ++i)
    {
        cout << setw(4) << a[i] << " \n"[(i + 1) % 10 == 0];
    }
    cout << "实际时间: " << seconds << " 秒" << endl;
    return 0;
}

void bubble_sort(int* num, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (num[j] > num[j + 1])
                swap(num[j], num[j + 1]);
        }
    }
}//冒泡排序

void select_sort(int* num, int n)
{
    int i, j, min_pos;
    for (i = 0; i < n - 1; ++i)
    {
        min_pos = i;
        for (j = i + 1; j < n; ++j)
        {
            if (num[j] < num[min_pos])
                min_pos = j;
        }
        swap(num[min_pos], num[i]);
    }
}//选择排序

void quick_sort(int* num, int left, int right)
{
    if (left < right)
    {
        int i = left - 1, j = right + 1, x = num[(left + right) / 2];
        while (i < j)
        {
            do
                i++;
            while (num[i] < x);

            do
                j--;
            while (num[j] > x);

            if (i < j)
                swap(num[i], num[j]);
        }
        quick_sort(num, left, j);
        quick_sort(num, j + 1, right);
    }
}//快速排序
