#include <stdio.h>
#include<string.h>
int main()
{
    char *zf[24]= {"one","two","three","four","five","six","seven","eight","nine",
                      "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
                      "a","both","another","first","second","third"
                     };                                                   //��ű�ʾ���ֵĵ��ʣ���Ϊ10��20ƽ����ȡ��100Ϊ0���ɲ��ô���
    int sz[24]= {1,4,9,16,25,36,49,64,81,21,44,69,96,25,56,89,24,61,1,4,1,1,4,9};  //��zf�������Ӧ����¼ÿ����ƽ��ȡ��100��ֵ
    char a[256];
    int b=0;
    int c[6];
    gets(a);          //������ո���ַ���
    const char *delimiters=" .";
    char *token=strtok(a,delimiters);      //�Կո�;��Ϊ�ָ����Ծ��ӽ��зָ�
    while(token!=NULL)
    {
        for(int i=0; i<24; i++)
        {
            if(strcmp(token,zf[i])==0)   //��zf����Ϊ��׼����������жϣ������
            {
                c[b]=sz[i];
                b++;
            }
        }
        token=strtok(NULL,delimiters);

    }
    int t;
    if(b==0) printf("%d",b);   //���û�б�ʾ���ֵĵ������0
    else
    {
        for(int i=0; i<b; i++)   //ͨ��ð��ʵ�����ִ�С��������
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
        printf("%d",c[0]);  //ȷ����λ������0
        for(int i=1; i<b; i++) printf("%02d",c[i]);  //ȷ������û0����������0����
    }
    return 0;
}

