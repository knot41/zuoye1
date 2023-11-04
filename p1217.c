#include<stdio.h>
#include<math.h>
int zhishu(int a)        //判断质数，后续只考虑自然数
{
    int flag;
    flag=1;
    if(a==0||a==1) flag=0;
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i==0) {flag=0;
        break;}
    }
    return flag;
}
int main()           //因为偶数位的回文数能被11整除，所以偶数位的回文质数只有11，可单独考虑
{
    int a,b;
    scanf("%d%d",&a,&b);
    int sz[100000];        //sz数组存放奇位数的回文数
    int hwz[100000];      //hwz数组存放为奇位数的回文质数
    int m=0;
    int j=0;
    int i1,i2,i3,i4,i5;
    for(i1=0; i1<=9; i1++)      //五重循环实现存放1、3、5、7、9位的回文数
        for(i2=0; i2<=9; i2++)
            for(i3=0; i3<=9; i3++)
                for(i4=0; i4<=9; i4++)
                    for(i5=0; i5<=9; i5++)
                    {
                        if(i1==0&&i2==0&&i3==0&&i4==0)sz[m++]=i5;
                        else
                        {
                            if(i1==0&&i2==0&&i3==0)sz[m++]=i4*101+i5*10;
                            else
                            {
                                if(i1==0&&i2==0)sz[m++]=i3*10001+i4*1010+i5*100;
                                else
                                {
                                    if(i1==0)sz[m++]=i2*1000001+i3*100010+i4*10100+i5*1000;
                                    else sz[m++]=i1*100000001+i2*10000010+i3*1000100+i4*101000+i5*10000;
                                }
                            }

                        }
                    }
    for(int k=0; k<m; k++)if(zhishu(sz[k])==1) hwz[j++]=sz[k];   //如果这些回文数还是质数则存放
    for(int k=0; k<j; k++)     //逐个遍历，在范围内则输出
    {
        if(hwz[k]<=b&&hwz[k]>=a)
        {
            if(k==4) printf("11\n");   //要记得处理11，k==0时对应2，k==1时对应3，k==2时对应5，k==3时对应7，k==4时对应101，如果101要被输出，则要先输出11
            printf("%d\n",hwz[k]);
        }
    }
    return 0;
}

