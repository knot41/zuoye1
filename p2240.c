#include<stdio.h>
int main()
{
    int n;
    int t;
    scanf("%d%d",&n,&t);
    int m[100];
    int v[100];
    double a[100];           //�����������飬ͬһ���±�ֱ��Ӧͬһ�ѽ�ҵ���������ֵ��ƽ����ֵ
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&m[i],&v[i]);
        a[i]=v[i]*1.0/m[i];
    }
    double t3;
    int t1;
    int t2;         //t1,t2,t3����������
    for(int i=0; i<n; i++)      //ͨ��ð��������ƽ����ֵ�ɸߵ��͵�˳�������˳����н���
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                t3=a[j];   //ͬʱ������������ֵ��ƽ����ֵ��ʵ��ÿһ���±궼��Ӧͬһ�ѽ��
                a[j]=a[j+1];
                a[j+1]=t3;
                t1=m[j];
                m[j]=m[j+1];
                m[j+1]=t1;
                t2=v[j];
                v[j]=v[j+1];
                v[j+1]=t2;
            }
        }
    }
    int k;
    k=0;  //��������ж�
    double sum=0;
    while(t>=m[k]&&k<n)   //û���겢�һ���ȫ�ŵ�k������
    {
        t-=m[k];
        sum+=v[k];
        k+=1;
    }
    if(k==n);   //�����˵����������䣬��������
    else sum+=t*a[k];  //û���꣬������ȫ�ŵ�k������
    printf("%.2f",sum);
}
