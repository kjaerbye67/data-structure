#include<stdio.h>
//折半查找的数组必须有序(从小到大)
int binary(int* data,int len,int value)
{
    int low=0;
    int high=len-1;
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if(data[mid]>value)
        {
            high=mid-1;
        }
        else if (data[mid]<value)
        {
            low=mid+1;
        }
        else
        {
            return mid;
        }
    }
}
int main()
{
    int arr[]={4,8,13,48,67,78,91,488};
    int len=sizeof(arr)/sizeof(arr[0]);
    int pos=binary(arr,len,48);
    printf("%d\n",pos);
    return 0;
}