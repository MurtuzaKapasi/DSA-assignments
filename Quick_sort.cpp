//Write a C++ program to store the monthly salary of an employee in an array. Sort array of numbers in ascending order using Quick sort and Display details of top five employees with the highest salary.
//murtuza kapasi

#include<iostream>
#include <algorithm>
using namespace std;

struct employee{
    string name;
    float salary;
};

int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int count=0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex =start + count;
    swap(arr[pivotIndex], arr[start]);

    int i=start,j=end;

    while(i<pivotIndex &&j>pivotIndex)
    {
        while(arr[i]<pivot){
            i++; }

        while(pivot<arr[j]){
            j--;}

        if(i <pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);
            //i++ and j-- becoz we want that element for which while loop condition is false
    }     
        return pivotIndex;
}

void quick(int arr[],int start,int end)
{   
    if(start>=end)
        return;
    int mid=partition(arr,start,end);
    quick(arr,start,mid-1);
    quick(arr,mid+1,end);
}

int main()
{
    int n=0;
    cout<<"Enter number of elements: ";
    cin>>n;
    employee e[n];
    int arr[n],l=0;
    cout<<"Enter elements:\n";
    for(int i=0 ; i<n  ; i++)
    {   cout<<"Enter name: ";
        cin>>e[i].name;
        cout<<"Enter salary: ";
        cin>>e[i].salary;
        arr[i]=e[i].salary;
    }

    int r=n-1;
    quick(arr,l,r);
    cout<<"Sorted array is:\n";
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"\nTop 5 Employee with highest salary are:\n";
    for(int i=n-1  ; i>=n-5 ; i--)
    {   
        
            for(int j=0 ; j<n ; j++)
            {
                if(arr[i]==e[j].salary)
                cout<<e[j].name<<"\t"<<e[j].salary<<endl;
            }
    }

    return 0;
}
