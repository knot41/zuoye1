#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[39][39];  //定义足够大的空间
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=0;  //初值设为零
        }
    }
    a[0][n/2]=1;
    int r=0;   //r为上一个数存放的行，c为上一个数存放的列
    int c=n/2;
    for(int i=2; i<=n*n; i++)
    {
        if(r==0&&c!=n-1)   //对应第一种情况
        {
            r=n-1;
            c=c+1;
            a[r][c]=i;
            continue;
        }
        if(r!=0&&c==n-1)   //对应第二种情况
        {
            r=r-1;
            c=0;
            a[r][c]=i;
            continue;
        }
        if(r==0&&c==n-1)   //对应第三种情况
        {
            r=r+1;
            a[r][c]=i;
            continue;
        }
        if(r!=0&&c!=n-1)   //对应第四种情况
        {
            if(a[r-1][c+1]==0)
            {
                r=r-1;
                c=c+1;
                a[r][c]=i;
                continue;   //更新后要及时退出
            }
            else
            {
                r=r+1;
                a[r][c]=i;
                continue;
            }
        }
    }
    for(int i=0; i<n; i++)   //输出
    {
        for(int j=0; j<n-1; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][n-1]);
    }
    return 0;
}
