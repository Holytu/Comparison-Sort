#include<iostream>
#include<array>
using namespace std;
void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int Partition(int left, int right, int arr[])
{
	int i = left ,j ;
	int pivot = arr[right];
	for(int j = left; j < right ; j++)
	{
		if(arr[j] < pivot)
		{
			Swap(&arr[i], &arr[j]);
			i++;
		}
	}
	Swap(&arr[i],&arr[right]);
	return i;
}
void QucikSort(int left, int right, int arr[])
{
	int pi;
	if(left < right)
	{
		pi = Partition(left, right, arr);
		QucikSort(left, pi-1, arr);
		QucikSort(pi+1, right, arr);
	}

}
void Print(int arr[], int len)
{
	cout<<"len = "<<len<<endl;
	for (int i = 0; i < len; i++)
	{
		if(i != len - 1)
			cout<<arr[i]<<", ";
		else 
			cout<<arr[i];
	}
	cout<<endl;
}
int main()
{
	int arr[]={84, 71, 14, 84, 25, 60, 37, 24, 35, 98};//10 elements
	QucikSort(0, 9, arr);
	int len = sizeof(arr) / sizeof(int);
	Print(arr, len);

}