#include <stdio.h>
int max(int x,int y)   //返回两数中较大的那个数
{
    int t;
    if(x<y)
    {
        t=x;
        x=y;
        y=t;
    }
    return x;
}
int main()
{
    int a[10][10];     //题目所给的是位置，为了方便，想将其转变为下标，因此在前一行和左一行再开个数组，容量因此变为10
    int b[10][10][10][10];  //四维数组，并无四维空间上的意义，在这表示到一个位置经过两条路径的最大值
    int n;
    scanf("%d",&n);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            a[i][j]=0;         //a数组初值设为0
            for(int k=0; k<=n; k++)
            {
                for(int t=0; t<=n; t++)
                {
                    b[i][j][k][t]=0;       //b数组初值设为0，理解为第一条路径到达a[i][j],第二条路径到达a[k][t]
                }
            }
        }
    }
    int x,y,t;
    scanf("%d%d%d",&x,&y,&t);
    while(x!=0)         //输入是人给的，只要x==0，就意味着要结束退出
    {
        a[x][y]=t;
        scanf("%d%d%d",&x,&y,&t);         //多组数据
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    for(int t=1; t<=n; t++)
                    {                          //因为只能向下向右，对b中某一个元素，相反处理并排列组合后从四组数据找出最大值
                        b[i][j][k][t]=max(max(b[i-1][j][k-1][t],b[i-1][j][k][t-1]),max(b[i][j-1][k-1][t],b[i][j-1][k][t-1]))+a[i][j]+a[k][t];
                        if(i==k&&j==t) b[i][j][k][t]-=a[i][j];   //因为走过的那个数只能用1遍，那么再用时加上了两遍，所以要减去一次
                    }
                }
            }
        }
    }
    printf("%d",b[n][n][n][n]);
    return 0;
}
