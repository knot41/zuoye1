#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int a[100];      //�����㹻�������������
    scanf("%d",&n);
    for(int i=0; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==0) printf("%d",a[n]);    //ֻ�г��������迼�ǣ�ֱ�����
    else
    {
        for(int i=0; i<=n; i++)     //�����������±�Ϊi��Ӧx��n-i�η�
        {
            if(a[i]==0) continue;
            if(i==n&&a[i]<0)
            {
                printf("%d",a[i]);
                break;       //�ж���ʱ���Գ�������д�����Ϊ����д�����⣬Ҫ��ʱ�˳�
            }
            if(i==n&&a[i]>0)
            {
                printf("+%d",a[i]);
                break;        //�ж���ʱ���Գ�������д�����Ϊ����д�����⣬Ҫ��ʱ�˳�
            }
            if(i==n-1&&a[i]>0&&a[i]!=1)
            {
                printf("+%dx",a[i]);
                continue;    //����x��һ�η�
            }
            if(i==n-1&&a[i]==1)
            {
                printf("+x");
                continue;   //����x��һ�η�
            }
            if(i==n-1&&a[i]<0&&a[i]!=-1)
            {
                printf("%dx",a[i]);
                continue;     //����x��һ�η�
            }
            if(i==n-1&&a[i]==-1)
            {
                printf("-x");
                continue;    //����x��һ�η�
            }
            if(i==0&&a[i]>0&&a[i]!=1) printf("%dx^%d",a[i],n-i);   //������λ���������
            if(i==0&&a[i]==1) printf("x^%d",n-i);
            if(a[i]<0&&a[i]!=-1) printf("%dx^%d",a[i],n-i);     //���������
            if(a[i]==-1) printf("-x^%d",n-i);
            if(i!=0&&a[i]>0&&a[i]!=1) printf("+%dx^%d",a[i],n-i);  //�������λ����������
            if(i!=0&&a[i]==1) printf("+x^%d",n-i);
        }
    }
    return 0;
}
