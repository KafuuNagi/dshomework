#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void random_num();//生成随机数
void copy_num();//复制随机数组

namespace stu1
{
	void shellSort(int A[], int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
			for (int i = gap; i < n; i++)
			{
				int key = A[i];
				int j = i - gap;
				while (j >= 0 && A[j] > key)
				{
					A[j + gap] = A[j];
					j -= gap;
				}
				A[j + gap] = key;
			}
	}//同学一的希尔排序 

	void merge(int A[], int left, int mid, int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;
		int L[n1], R[n2];

		for (int i = 0; i < n1; i++)
		{
			L[i] = A[left + i];
		}
		for (int j = 0; j < n2; j++)
		{
			R[j] = A[mid + j + 1];
		}
		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				A[k++] = L[i++];
			}

			else
			{
				A[k++] = R[j++];
			}
		}
		while (i < n1)
		{
			A[k++] = L[i++];
		}
		while (j < n2)
		{
			A[k++] = R[j++];
		}
	}
	void mergeSort(int A[], int left, int right)
	{
		if (right > left)
		{
			int mid = left + (right - left) / 2;

			mergeSort(A, left, mid);
			mergeSort(A, mid + 1, right);
			merge(A, left, mid, right);
		}
	}//同学一的归并排序 

	void heapify(int A[], int n, int i)
	{
		int largest = i;//初始化根节点为最大值
		int left = 2 * i + 1;//左子节点 
		int right = 2 * i + 2; //右子节点

		//如果左子节点比根节点大 
		if (left<n && A[left]>A[largest])
			largest = left;

		if (right<n && A[right]>A[largest])
			largest = right;

		if (largest != i)
		{
			swap(A[i], A[largest]);

			heapify(A, n, largest);
		}
	}
	void heapSort(int A[], int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(A, n, i);
		}


		for (int i = n - 1; i > 0; i--)
		{
			swap(A[0], A[i]);
			heapify(A, i, 0);
		}

	}//同学一：堆排序

	void bubbleSort(int A[], int n)
	{
		bool swapped = true;
		for (int i = 0; i < n - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (A[j] > A[j + 1])
				{
					swap(A[j], A[j + 1]);
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}

	} //同学一： 冒泡排序 

	void selectionSort(int A[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < n; j++)
			{
				if (A[j] < A[minIndex])
					minIndex = j;
			}
			swap(A[minIndex], A[i]);
		}
	}//同学一：选择排序 

	int partition(int A[], int low, int high)
	{
		int pivot = A[low];
		int i = low, j = high;
		while (i < j)
		{
			while (i < j && A[j] >= pivot)j--;
			if (i < j)A[i++] = A[j];

			while (i < j && A[i] <= pivot)i++;
			if (i < j)A[j--] = A[i];
		}
		A[i] = pivot;//基准值归位
		return i;
	}

	void quickSort(int A[], int left, int right)
	{
		if (left < right)
		{
			int pivotIndex = partition(A, left, right);
			quickSort(A, left, pivotIndex - 1);
			quickSort(A, pivotIndex + 1, right);
		}
	}//同学一：快速排序 
	
	void insertionSort(int A[],int n)
	{
		for(int i=1;i<n;i++)
		{
			int key=A[i];
			int j=i-1;
			while(j>=0&&A[j]>key)
			{
				A[j+1]=A[j];
				j--;
			}
		A[j+1]=key;
	}
	}//同学一：插入排序 
}

namespace stu2
{
	bool changed = false;
	void bubbleSort(int a[],int l)
	{
		for(int i=l;i>0;i--)
 		{
  			changed=false;
  			for(int j=1;j<i;j++)
   				if(a[j-1]>a[j])
   				{
    				swap(a[j-1],a[j]);
    				changed=true; 
   				}
  			if(!changed) 
   			break;
 		}  
	}
}//同学二：冒泡排序 

namespace stu3
{
	void selectionSort(int p[],int size)
	{
		int temp;
 		int index;
 		for(int i=0;i<size;i++)
 		{
  			index=i;    
  			temp=p[i];
  			for(int j=i+1; j<size; j++)
  			{
   				if(p[index]>p[j])
   				{ 
    				index=j;
   				}
  			}
  			p[i]=p[index];
  			p[index]=temp;
 		}
	}
}//同学三：选择排序

const int MAX = 10000;
const int WAY = 9;
int a[MAX];
int b[WAY][MAX];//随机数生成与拷贝模块

auto start = chrono::high_resolution_clock::now();
auto stop = chrono::high_resolution_clock::now();
double seconds;//时间计算模块


int main()
{
	bool showStu1 = true;
	bool showStu2 = true;
	bool showStu3 = true; //是否要比较某位同学的算法
	
	random_num();
	copy_num();

	int i = 0;

	while (showStu1) //同学一
	{
		using namespace stu1;

		cout << "同学一：冒泡排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		bubbleSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;

		cout << "同学一：选择排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		selectionSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;
		
		cout << "同学一：插入排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		insertionSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;
		
		cout << "同学一：快速排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		quickSort(b[i], 0, MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;

		cout << "同学一：希尔排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		shellSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;

		cout << "同学一：归并排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		mergeSort(b[i], 0, MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;

		cout << "同学一：堆排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		heapSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;
		
		cout << endl;
		break;
	}
	
	while(showStu2)
	{
		using namespace stu2;
		
		cout << "同学二：冒泡排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		bubbleSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;
		
		cout << endl;
		break;
	 } 
	 
	 while(showStu3)
	{
		using namespace stu3;
		
		cout << "同学三：选择排序" << "   " << "用时：";
		start = chrono::high_resolution_clock::now();
		selectionSort(b[i], MAX);
		stop = chrono::high_resolution_clock::now();
		seconds = chrono::duration<double>(stop - start).count();
		cout << seconds << "秒" << endl;
		++i;
		
		cout << endl;
		break;
	 } 
}

void random_num()
{
	cout << "生成随机数中……" << endl;
	srand(time(0));
	for (int i = 0; i < MAX; ++i)
	{
		a[i] = rand() % 1000;
	}
}

void copy_num()
{
	cout << "复制随机数组中……" << endl;
	int i, j;
	for (i = 0; i < WAY; ++i)
	{
		for (j = 0; j < MAX; ++j)
			b[i][j] = a[j];
	}
}

