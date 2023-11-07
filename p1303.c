#include <stdio.h>
#include<string.h>
int main()
{
    int a[2000],b[2000];  //此题数字最大到10的2000次方，肯定不能用int类型的变量存储，考虑用int数组,一位对应数字的一位
    char a1[2001],b1[2001];   //但输入时并不能按一位对应一位的方式给int数组，考虑通过字符串实现数组位位对应，因为字符串后带‘/0’，空间要加1
    int c[4000];        //c数组存放乘积后的结果
    scanf("%s%s",a1,b1);
    int la,lb;
    la=strlen(a1);    //la为数a的位数，lb为数b的位数
    lb=strlen(b1);
    for(int i=0; i<la; i++) a[i]=a1[i]-48;  //字符串中字符‘0’是int的48.所以转换时要减去48
    for(int i=0; i<lb; i++) b[i]=b1[i]-48;
    for(int i=0; i<la+lb; i++) c[i]=0;   //a位数乘积b位数最多得到a+b位数，首先全赋值为0，来考虑实际位数
    for(int i=la-1; i>=0; i--)
    {
        for(int j=lb-1; j>=0; j--)
        {
            c[i+j+1]+=a[i]*b[j];   //通过举例子发现，a中下标为i的乘上b中下标为j的，在c中下标应该对应i+j+1;
        }
    }
    for(int i=la+lb-1; i>=0; i--)   //转为十进制，位位对应
    {
        if(c[i]>=10)
        {
            c[i-1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
    int k;
    k=la+lb;    //正常来说 k在下面循环中是不会取到la+lb的，后续拿来判断结果是否为零用
    for(int i=0; i<la+lb; i++)
    {
        if(c[i]!=0)
        {
            k=i;
            break;    //因为实际结果的位数不确定，要找到第一个不为0的数作为开头输出
        }
    }
    if(k==la+lb) printf("0");   //如果都为0，说明k没更新，即结果为零
    for(int i=k; i<la+lb; i++)
    {
        printf("%d",c[i]);  //从第一个不为0的数开始按顺序输出
    }
    return 0;
}
