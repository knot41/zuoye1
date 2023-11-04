#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int a[100];      //定义足够大的数组存放数字
    scanf("%d",&n);
    for(int i=0; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==0) printf("%d",a[n]);    //只有常数项无需考虑，直接输出
    else
    {
        for(int i=0; i<=n; i++)     //挨个遍历，下标为i对应x的n-i次方
        {
            if(a[i]==0) continue;
            if(i==n&&a[i]<0)
            {
                printf("%d",a[i]);
                break;       //有多项时，对常数项进行处理，因为后续写法问题，要及时退出
            }
            if(i==n&&a[i]>0)
            {
                printf("+%d",a[i]);
                break;        //有多项时，对常数项进行处理，因为后续写法问题，要及时退出
            }
            if(i==n-1&&a[i]>0&&a[i]!=1)
            {
                printf("+%dx",a[i]);
                continue;    //处理x的一次方
            }
            if(i==n-1&&a[i]==1)
            {
                printf("+x");
                continue;   //处理x的一次方
            }
            if(i==n-1&&a[i]<0&&a[i]!=-1)
            {
                printf("%dx",a[i]);
                continue;     //处理x的一次方
            }
            if(i==n-1&&a[i]==-1)
            {
                printf("-x");
                continue;    //处理x的一次方
            }
            if(i==0&&a[i]>0&&a[i]!=1) printf("%dx^%d",a[i],n-i);   //处理首位的正数情况
            if(i==0&&a[i]==1) printf("x^%d",n-i);
            if(a[i]<0&&a[i]!=-1) printf("%dx^%d",a[i],n-i);     //处理负数情况
            if(a[i]==-1) printf("-x^%d",n-i);
            if(i!=0&&a[i]>0&&a[i]!=1) printf("+%dx^%d",a[i],n-i);  //处理除首位外的正数情况
            if(i!=0&&a[i]==1) printf("+x^%d",n-i);
        }
    }
    return 0;
}
