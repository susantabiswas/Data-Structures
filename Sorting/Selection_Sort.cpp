//Selection Sort using Array
#include<iostream>
using namespace std;


//For performing Selection sort
void SelectionSort(int *arr,int size)
{	int swap=0;
	int min=0;
	for (int i = 0; i < size-1; ++i)
	{
		min=i;
		for (int j = i; j < size; ++j)
		{
			//if the previous element is greater than the next swap the elements
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		//swap the minimum element at its position
		swap=arr[min];
		arr[min]=arr[i];
		arr[i]=swap;
	}

}

int main()
{
	int a[9];
	int j=0;
	//array creation
	a[0]=5;
	a[1]=4;
	a[2]=3;
	a[3]=2;
	a[4]=3;
	for(int i=5;i<9;i++)
		a[i]=i;
	cout<<"Before sorting:\n";
	for (int i = 0; i<9; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	SelectionSort(a,9);
	cout<<endl<<"After Sorting:\n";
	for (int i = 0; i<9; ++i)
	{
		cout<<a[i]<<" ";
	}
}
