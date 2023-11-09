#include <stdio.h>
int a[5000000];
int dg(int l,int r,int k)   //分治考虑递归
{
    int i=l;         //因为冒泡，选择排序啥的复杂度为n的平方，不考虑用这类排序
    int j=r;
    int pivot=a[l];       //学习了一下效率更高的快速排序，确定pivot的位置
    while(i<j)
    {
        while(i<j&&a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            a[i++]=a[j];      //比pivot小的数放左边
        }
        while(i<j&&a[i]<pivot)
        {
            i++;
        }
        if(i<j)
        {
            a[j--]=a[i];    //比pivot大的数放右边
        }

    }
    a[i]=pivot;                  //最后确定pivot的位置，即下标为i的位置
    if(k==i) printf("%d",a[k]);    //如果将全数组全部快排，提交结果发现最后一组数据超时，所以优化考虑判断当时pivot是否为第k位
    else if(k<i)dg(l,i-1,k);    //k小的话，则只需要在pivot的左边进行快排
    else  dg(i+1,r,k);      //k大的话，只需要在pivot的右边进行快排
    return 0;
}
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    dg(0,n-1,k);
    return 0;
}
