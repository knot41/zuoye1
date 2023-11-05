#include<stdio.h>
#include<math.h>
int a[1024][1024];          //定义一个足够大的二维数组
int dg(int x,int y,int s)   //因为每次操作相同，考虑递归算法
{
    {
        if(s==1)          //如果最后分割到的矩阵长度为1，不做处理，结束运行，虽然这会有些数据没有返回值的警告，但本题不会有这种情况发生
        {
            return 0;
        }
    }
    for(int i=x; i<x+s/2; i++)
    {
        for(int j=y; j<y+s/2; j++)
        {
            a[i][j]=0;           //对当前矩阵的左上部分进行赦免处理
        }
    }
    dg(x+s/2,y,s/2);         //对上一个矩阵左上部分处理完后，处理其右上部分，长度减少至一半
    dg(x,y+s/2,s/2);         //对上一个矩阵左上部分处理完后，处理其左下部分，长度减少至一半
    dg(x+s/2,y+s/2,s/2);     //对上一个矩阵左上部分处理完后，处理其右下部分，长度减少至一半
}
int main()
{
    int n;
    scanf("%d",&n);
    int s;
    s=(int)pow(2,n);       //pow返回double，强制转换为int
    for(int i=0; i<s; i++)          //数组a先全赋值为1，表示还未赦免
    {
        for(int j=0; j<s; j++)
        {
            a[i][j]=1;
        }
    }
    dg(0,0,s);
    for(int i=0; i<s; i++)           //递归完后按要求进行输出
    {
        for(int j=0; j<s; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");         //一行输出记得换行
    }
    return 0;
}
