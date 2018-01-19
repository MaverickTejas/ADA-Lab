#include<iostream>
using namespace std;
int  partition(int arr[],int l,int u);
void mergesort(int [],int,int);

class sortings
{
  public:
          void quick(int arr[],int l,int u);
          void merge(int arr[],int start,int middle,int end);
          void insert(int arr[],int n);
};

void sortings::quick(int arr[10],int l,int u)
{

    int j;
    if(l<u)
    {
        j=partition(arr,l,u);
        quick(arr,l,j-1);
        quick(arr,j+1,u);
    }
}
int partition(int arr[10],int l,int u)
{
    int v,i,j,temp;
    v=arr[l];
    i=l;
    j=u+1;
    do
    {
        do{
            i++;

        }while(arr[i]<v&&i<=u);
        do{
            j--;
        }while(v<arr[j]);
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    arr[l]=arr[j];
    arr[j]=v;
    return(j);
}
void sortings::merge(int arr[10],int start,int middle,int end)
{
int i, j, k;
    int n1 = middle - start + 1;
    int n2 =  end - middle;
    int L[30], R[30];
    for (i = 0; i < n1; i++)
    L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
    R[j] = arr[middle + 1+ j];
    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
    if (L[i] <= R[j])
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
    }
    while (i < n1)
    {
    arr[k] = L[i];
    i++;
    k++;
    }
    while (j < n2)
    {
    arr[k] = R[j];
    j++;
    k++;
    }
}
void mergesort(int arr[10], int start,int end)
{

    if (start < end)
    {
    int middle =start+(end-start)/2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);
    merge(arr, start, middle, end);
    }
}
void sortings::insert(int arr[], int n)
{
                int j, temp;

        for (int i = 0; i < n; i++)
               {
                j = i;

                     while (j > 0 && arr[j] < arr[j-1])
                          {
                          temp = arr[j];
                          arr[j] = arr[j-1];
                          arr[j-1] = temp;
                          j--;
                          }
                }
}
int main()
{
sortings S;
int arr[10],n,i,choice;
cout<<"\nEnter the no. of elements in the array";
cin>>n;
cout<<"\n Enter the array elements: ";
for(i=0;i<n;i++)
cin>>a[i];
cout<<"\n Enter option \n1.quick sort\n2.insertion sort\n3.merge sort\n: ";
cin>>choice;
switch(choice)
{
 case 1:  S.quick(arr[i],0,n-1);
          cout<<"\nArray after sorting:";
          for(i=0;i<n;i++)
          cout<<arr[i]<<" ";
 case 2:  S.merge(arr,0,(n-1)/2,n-1);
          mergeSort(arr[i], 0, n-1);
          cout<<"\n Array after sorting : ";
          for(i=0;i<n;i++)
          cout<<arr[i]<<" ";
 case 3:  S.insert(arr[i],n);
          cout<<"\n Arrray after sorting : ";
          for(i=0;i<n;i++)
          cout<<arr[i]<<" ";
}
return 0;
}

