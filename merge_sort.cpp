
//Write a C++ program to store the monthly salary of an employee in an array. Sort array of numbers in ascending order using Merge sort and Display details of top five employees with the highest salary.
//murtuza kapasi

#include<iostream>
#include<algorithm>
using namespace std;


struct employee{
    string name;
    float salary;
};

void merge(int arr[],int beg,int mid,int end)
{   
    int  n1=mid-beg+1;
    int  n2=end-mid;
    int left[n1],right[n2];

    for(int i=0 ; i<n1 ; i++)
        left[i]=arr[i+beg];

    for(int j=0 ; j<n2 ; j++)
        right[j]=arr[mid+j+1];

    int i=0,j=0,k=beg;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
            k++;
    }

    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        k++;
        j++;
    }
}

void merge_sort(int arr[],int beg,int end)
{   
    if(beg<end)
    {
        int mid=beg + (end - beg)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main()
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    employee e[n];
    int arr[n],start=0,end;
    cout<<"Enter elements:\n";
    for(int i=0 ; i<n  ; i++)
    {   cout<<"Enter name: ";
        cin>>e[i].name;
        cout<<"Enter salary: ";
        cin>>e[i].salary;
        arr[i]=e[i].salary;
    }

    end=n-1;
    merge_sort(arr,start,end);
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

