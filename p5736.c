#include<stdio.h>
#include<math.h>
int zhishu(int x) //判断是否为质数
{
    int flag=1;
    if(x==1) flag=0;
    for(int i=2; i<=sqrt(x); i++)
    {
        if(x%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n;
    scanf("%d\n",&n);
    int a[100];    //定义足够大的空间
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        if(zhishu(a[i])==1) //是质数就输出
        {
            printf("%d ",a[i]);
        }
    }

    return 0;
}
