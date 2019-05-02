#include <iostream>

using namespace std;
void CountingSort(int arr[], int n)
{
	int *count_arr = new int[n];
	int *new_arr = new int[n];
	int k = 0;
	
	for(int i = 0; i < n; i++)
	{
		count_arr[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		count_arr[arr[i] - 1]++;
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d : %d\n", i + 1, count_arr[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		while(count_arr[i] > 0)
		{
			arr[k] = i + 1;
			count_arr[i]--;
			k++;
		}
	}

	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	
	cout<<"\n";
}

int main()
{
	int arr[] = {9, 8, 3, 3, 9, 2, 4, 6, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	CountingSort(arr, n);

	return 0;
}