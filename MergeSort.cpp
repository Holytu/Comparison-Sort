#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void Print(int arr[],int count)
{
	for (int i = 0; i < count; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Merge(int left, int middle, int right, int arr[])
{
	int n1, n2 , i, j, k;
	
	n1 = middle - left + 1;
	n2 = right - middle;

	int left_arr[n1];
	int right_arr[n2];

	for (i = 0; i < n1 ; i++)
	{
		left_arr[i] = arr[ left + i ];
	}

	for (j = 0; j < n2 ; j++)
	{
		right_arr[j] = arr[ 1 + j + middle ];
	}

	i = 0;//left_arr
	j = 0;//right_arr
	k = left;
	while( i < n1 && j < n2 )
	{
		if (left_arr[i] <= right_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else 
		{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}
	while( i < n1 )
	{
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	while( j < n2 )
	{
		arr[k] = right_arr[j];
		j++;
		k++;
	}

}
void MergeSort(int left, int right, int arr[])
{
	if(left < right)
	{
		int middle = (left + right) / 2 ;
		MergeSort(left, middle, arr);
		MergeSort(middle + 1, right, arr);
		Merge(left, middle, right, arr);
	}
}

int main()
{
	int arr[]={12, 11, 13, 5, 6, 7};//6 elements
	int len = sizeof(arr) / sizeof(int);

	MergeSort(0, len - 1, arr);
	Print(arr, len);
}