#include<stdio.h>
    int a[400000];                //a数组存放输入的数据，即每一个位置的冰冻指数，实际上会用到n+r个空间，所以为400000
    int b[400000];                //b数组运用动态规划存放每个位置的最大的冰冻指数
    int q[400000];                //q数组为队列，存放的是下标
int max(int x,int y)             //返回较大数
{
    if(x<y) x=y;
    return x;
}
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n+1; i<=n+r; i++)
    {
        a[i]=0;                 //从n+1到n+r可结束，认为这些区域的冰冻指数为0
    }
    for(int i=1; i<=n+r; i++)
    {
        b[i]=-1000;           //因为存在负数情况，不能单纯设置为0
    }
    b[0]=0;             //第0位为0
    int h,t;
    h=0;
    t=-1;                //头尾指针
    for(int i=0; i<=n+r-l; i++)
    {
        while(h<=t&&i-q[h]>r-l) h++;   //队非空并且长度满了，队头往后走
        while(h<=t&&b[q[t]]<=b[i]) t--;  //队非空并且新的位置对应的冰冻指数更大，队尾往前走
        q[++t]=i;         //入队
        b[i+l]=b[q[h]]+a[i+l];     //动态规划，b[q[h]]能够决定往后l以内的数
    }
    int ans=-1e9;
    for(int i=n+1; i<=n+r; i++)
    {
        ans=max(ans,b[i]);  //从能退出的地方找出最大值
    }
    printf("%d",ans);
    return 0;
}
