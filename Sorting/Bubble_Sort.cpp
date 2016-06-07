//Bubble Sort using Array
#include<iostream>
using namespace std;


//For performing bubble sort
void BubbleSort(int *arr,int size)
{	int swap=0;
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size-1-i; ++j)
		{
			//if the previous element is greater than the next swap the elements
			if(arr[j]>arr[j+1])
			{
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
			}
		}
	}

}

int main()
{
	int a[5];
	int j=0;
	//array creation
	a[0]=5;
	a[1]=4;
	a[2]=3;
	a[3]=2;
	a[4]=3;
	cout<<"Before sorting:\n";
	for (int i = 0; i<5; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	BubbleSort(a,5);
	cout<<endl<<"After Sorting:\n";
	for (int i = 0; i<5; ++i)
	{
		cout<<a[i]<<" ";
	}
}
