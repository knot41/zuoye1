#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[39][39];  //�����㹻��Ŀռ�
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            a[i][j]=0;  //��ֵ��Ϊ��
        }
    }
    a[0][n/2]=1;
    int r=0;   //rΪ��һ������ŵ��У�cΪ��һ������ŵ���
    int c=n/2;
    for(int i=2; i<=n*n; i++)
    {
        if(r==0&&c!=n-1)   //��Ӧ��һ�����
        {
            r=n-1;
            c=c+1;
            a[r][c]=i;
            continue;
        }
        if(r!=0&&c==n-1)   //��Ӧ�ڶ������
        {
            r=r-1;
            c=0;
            a[r][c]=i;
            continue;
        }
        if(r==0&&c==n-1)   //��Ӧ���������
        {
            r=r+1;
            a[r][c]=i;
            continue;
        }
        if(r!=0&&c!=n-1)   //��Ӧ���������
        {
            if(a[r-1][c+1]==0)
            {
                r=r-1;
                c=c+1;
                a[r][c]=i;
                continue;   //���º�Ҫ��ʱ�˳�
            }
            else
            {
                r=r+1;
                a[r][c]=i;
                continue;
            }
        }
    }
    for(int i=0; i<n; i++)   //���
    {
        for(int j=0; j<n-1; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("%d\n",a[i][n-1]);
    }
    return 0;
}
