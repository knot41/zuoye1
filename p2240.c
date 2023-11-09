#include<stdio.h>
int main()
{
    int n;
    int t;
    scanf("%d%d",&n,&t);
    int m[100];
    int v[100];
    double a[100];           //定义三个数组，同一个下标分别对应同一堆金币的重量，价值，平均价值
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&m[i],&v[i]);
        a[i]=v[i]*1.0/m[i];
    }
    double t3;
    int t1;
    int t2;         //t1,t2,t3拿来交换用
    for(int i=0; i<n; i++)      //通过冒泡排序以平均价值由高到低的顺序对数组顺序进行交换
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                t3=a[j];   //同时交换重量，价值，平均价值，实现每一个下标都对应同一堆金币
                a[j]=a[j+1];
                a[j+1]=t3;
                t1=m[j];
                m[j]=m[j+1];
                m[j+1]=t1;
                t2=v[j];
                v[j]=v[j+1];
                v[j+1]=t2;
            }
        }
    }
    int k;
    k=0;  //逐个进行判断
    double sum=0;
    while(t>=m[k]&&k<n)   //没放完并且还能全放第k项的情况
    {
        t-=m[k];
        sum+=v[k];
        k+=1;
    }
    if(k==n);   //放完了的情况，空语句，不做处理
    else sum+=t*a[k];  //没放完，但不能全放第k项的情况
    printf("%.2f",sum);
}
