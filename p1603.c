#include <stdio.h>
#include<string.h>
int main()
{
    char *zf[24]= {"one","two","three","four","five","six","seven","eight","nine",
                      "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
                      "a","both","another","first","second","third"
                     };                                                   //存放表示数字的单词，因为10和20平方后取余100为0，可不用处理
    int sz[24]= {1,4,9,16,25,36,49,64,81,21,44,69,96,25,56,89,24,61,1,4,1,1,4,9};  //和zf数组相对应，记录每个数平方取余100的值
    char a[256];
    int b=0;
    int c[6];
    gets(a);          //输入带空格的字符串
    const char *delimiters=" .";
    char *token=strtok(a,delimiters);      //以空格和句号为分隔符对句子进行分割
    while(token!=NULL)
    {
        for(int i=0; i<24; i++)
        {
            if(strcmp(token,zf[i])==0)   //以zf数组为标准，逐个进行判断，并存放
            {
                c[b]=sz[i];
                b++;
            }
        }
        token=strtok(NULL,delimiters);

    }
    int t;
    if(b==0) printf("%d",b);   //如果没有表示数字的单词输出0
    else
    {
        for(int i=0; i<b; i++)   //通过冒泡实现数字从小到大排列
        {
            for(int j=0; j<b-1-i; j++)
            {
                if(c[j]>c[j+1])
                {
                    t=c[j];
                    c[j]=c[j+1];
                    c[j+1]=t;
                }
            }
        }
        printf("%d",c[0]);  //确保首位不能有0
        for(int i=1; i<b; i++) printf("%02d",c[i]);  //确保后面没0的数字能有0补上
    }
    return 0;
}

