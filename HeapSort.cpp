#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Adjust(int arr[], int node, int size)
{
	int L_child = node * 2 , R_child = node * 2 + 1;
	int parent = node;

	if(L_child < size && arr[L_child] < arr[parent])
	{
		parent = L_child;
	}
	if(R_child < size && arr[R_child] < arr[parent])
	{
		parent = R_child;
	}

	if(parent != node)
	{
		Swap( &arr[parent], &arr[node]);
		Adjust(arr, node, size);
	}

}
void heapSort(int arr[], int size)
{
	for(int i = size / 2 - 1; i >=0 ; i--)
	{
		Adjust(arr, i, size);
	}

	for(int i = size - 1; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);

		Adjust(arr, i , 0);
	}
}
int main()
{
	int arr[]={12, 11, 13, 5, 6, 7} ; //6 elements
	//int arr[]={9,4,1,6,7,3,8,2,5};
	int size = sizeof(arr) / sizeof(int);
	
	heapSort(arr, size) ; //Min heap
	PrintArray(arr, size);
	
}