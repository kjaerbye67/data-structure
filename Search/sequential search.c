#include<stdio.h>
int search(int* data,int len,int value)
{
    for(int i=0;i<len;i++)
    {
        if(data[i]==value)
        {
            return i;
        }
    }
    return -1;//下标可能为0
}
int main()
{
    int arr[]={13,78,91,13,48,8,67};
    int len=sizeof(arr)/sizeof(arr[0]);
    int pos=search(arr,len,91);
    printf("%d\n",pos);
    return 0;
}