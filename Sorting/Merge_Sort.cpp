//Merge Sort using Array
#include<iostream>
using namespace std;

//For Merging the two subarrays
//l:lower index,m=:mid index,h:higher index
void Merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    //copy the arrays into temporary arrays
    int a1[n1];
    int a2[n2];

//copy elements in the temporary arrays
    for (int i = 0; i <n1; ++i)
    {
        a1[i]=arr[i+l];
    }

    for (int i = 0; i < n2; ++i)
    {
        a2[i]=arr[i+m+1];
    }

    //starting index of first ,second subarrays and merged array
    int i=0,j=0,index=l;
    while(i<n1 && j<n2)
    {
        if (a1[i]<a2[j])
        {
            arr[index++]=a1[i++];
        }
        else
        {
            arr[index++]=a2[j++];
        }
    }

    //if a1 has finished while a2 is left
    while(i>=n1 && j<n2)
        arr[index++]=a2[j++];
    //if s2 has finished while a1 is left
     while(j>=n2 && i<n1)
        arr[index++]=a1[i++];
}

//For performing Merge sort
void MergeSort(int arr[],int l,int h)
{
    //if the array has only one element or empty
   if(l<h)
  {
    int m=(l+h)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,h);

    //merge the subarrays
    Merge(arr,l,m,h);
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
    MergeSort(a,0,4);
    cout<<endl<<"After Sorting:\n";
    for (int i = 0; i<5; ++i)
    {
        cout<<a[i]<<" ";
    }
}
