#include <iostream>

using namespace std;
void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
void RadixSort(int arr[], int n)
{
	int flag;
	int decimal = 1;
	int *brr = new int[n];
	int *copy_arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		copy_arr[i] = arr[i];
	}

	while(true)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
		{
			if(decimal > arr[i])
			{
				flag++;
			}
		}

		

		for (int i = 0; i < n; i++)
		{
			brr[i] = arr[i] % 10;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if( brr[i] > brr[j] )
				{
					Swap(&brr[i], &brr[j]);
					Swap(&arr[i], &arr[j]);
					Swap(&copy_arr[i], &copy_arr[j]);
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i] - brr[i];
			arr[i] = arr[i] / 10;
		}

		if(flag == n)
			break; 

		decimal = decimal * 10;

	}
	PrintArray(copy_arr, n);
}
int main()
{
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr) / sizeof(arr[0]);

	RadixSort(arr, n);

	return 0;
}